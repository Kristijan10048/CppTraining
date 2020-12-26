

#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#include <stdlib.h>


#pragma argsused
int main(int argc, char* argv[])
{
int n;
float t;
cout<<"Na kolku decimali:";
cin>>n;
t=1;
for (int i=1;i<=n; i++)
t=t/10;
cout<<t;

float pi1=0, spi1,zn=-1;;
int k=0;
do
 {
  spi1=pi1;
  zn=-zn;
  pi1=pi1+zn/(2*k-1);
  cout<<pi1;
  k++;
 }
while (abs(4*pi1-4*spi1)<t);
cout<<pi1;
int g;
cin>>g;

        return 0;
}

