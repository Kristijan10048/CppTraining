.386
.386
.model flat, stdcall
.stack 4096

ExitProcess PROTO, dwExitCode:DWORD

.data
myList DWORD 2, 3, 5, 8

.code
main PROC
  mov eax, 0
  add eax, 1
  incr:
  inc eax
  cmp eax, 9h
  jne incr
  INVOKE ExitProcess, eax
main ENDP

END main        ;specify the program's entry point