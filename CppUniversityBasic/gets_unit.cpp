#include <ctype.h>
#include <vcl.h>
#include <iostream.h>
#include <stdio.h>
#pragma hdrstop
#pragma argsused
#include <locale.h>
#include <string.h>
#include <typeinfo.h>


char p,c;
int n,i,j;
string t1;
int main(int argc, char* argv[])
{
cout<<"Vnesi go tekstot vo koj sakas da baras samoglski:";
cin>>(t);
n=t.length();
cout<<"Dolzinata na stringot e";
cout<<n<<endl;
i=0;
cout<<"Samoglaski vo teskstot se:\n";
while (i<=n)

    {
     if ((t[i]=='a') || (t[i]=='e') || (t[i]=='u') || (t[i]=='i'))
      {
       cout<<t[i];
       for (int k=i; k<=n-1; k++)
        {
        t[k]=t[k+1];
        }
      }
     i++;
    }
cout<<"Tekstot bez samoglaski izgleda vaka:";
cout<<t;
cin>>n;
        return 0;
}

