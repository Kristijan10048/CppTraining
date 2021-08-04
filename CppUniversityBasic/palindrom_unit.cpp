#ifdef NOT_FIXED

#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#pragma argsused

char zbor[50];
bool pal;
int n,i;

int main(int argc, char* argv[])
{
cout<<"Vnesi go zborot sto sakas da proveris dali e palindrom:";
cin>>zbor;
n=strlen(zbor);
pal=true;
i=0;
while (pal==true && i<=n/2)
  {
   if (zbor[i]!=zbor[n-i-1]){pal=false;}
    
   i++;
  }
if (pal==true) {cout<<"Zborot sto go vnese e palindrom" ;}
 else
    {cout<<"Zborot sto go vnese ne e palindrom" ;}
    
int g;
cin>>g;

        return 0;
}
#endif