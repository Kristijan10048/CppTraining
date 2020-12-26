#pragma hdrstop
#pragma argsused

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
int faktoriel(int n,int b=1);
int faktoriel(int n,int b)
{
 if(n==1)
  {
   return(b);
  }
 else
 {
  b=b*n;
  faktoriel(n-1,b);
 }
}

int niza[10];
void popolniniza(int pocetok,int kraj);
void popolniniza(int pocetok,int kraj)
{
for(int i=0;i<kraj-pocetok;i++)
 {
  niza[i]=pocetok;
  pocetok++;
 }
}

void prniza(int pocetok,int kraj);
void prniza(int pocetok,int kraj)
{
 for(int i=0;i<kraj-pocetok;i++)
  cout<<niza[i]<<"-";
}

int main(int argc, char* argv[])
{
char iz;
do
{
 clrscr();
 cout<<"1.Rekurzivno presmetuvanje na faktoriel"<<endl;
 cout<<"2.Presmetuvanje na permutacii"<<endl;
 cout<<"0.Izlez"<<endl;
 iz=getch();
 switch(iz)
 {
  case '1':
  {
   int br;
   cout<<"Broj";
   cin>>br;
   cout<<faktoriel(br);
   break;
  }
  case '2':
   {
    int p,kr;
    clrscr();
    cout<<"Pocetna vr:";
    cin>>p;
    cout<<endl<<"Krajna vr:";
    cin>>kr;
    popolniniza(p,kr);
    prniza(p,kr);
    system("pause");
    break;
   }
 } 
}
while(iz!='0');
system("pause");
        return 0;
}
//---------------------------------------------------------------------------
