# include <iostream.h>
# include<conio.h>
#pragma hdrstop
#pragma argsused
#include <string.h>
void printadr(int *pok);
void intpok();
void charpok();
char* invertch(char pcharni[20]);

void printadr(int *point)
 {
  int i;
  cout<<"Vrednosta na Point e:"<<*point<<endl;
  cout<<"Adresata na point e:"<<point<<" amp:"<<&point<<endl;
  for(i=1;i<=256;i+=8)
   {
    point+i;
    *point+=i;
    cout<<"Vrednostana point vcik e:"<<*point<<endl;
    cout<<"Adresata na point vcik e:"<<point<<" amp:"<<&point<<endl;
   }
 }

void intpok()
 {
  void *pok;
  int *inpok=0,a;
  a=1012;
  inpok=&a;
  pok=inpok;
  cout<<"Vrednosta na inpok e:"<<*inpok<<endl;
  cout<<"Adersata na inpok e: "<<inpok<<" amp"<<&inpok<<endl;
  cout<<"Adresata na pok e:   "<<pok<<" amp:"<<&pok<<endl;
  printadr(inpok);
  cout<<"-----------------------------------------------------------"<<endl;
  cout<<"Press eny key"<<endl;
  getch();
  clrscr();
 }

char* invertch(char pcharni[20])
{
 int i,n;
 n=strlen(pcharni)-1;
 char pom;

 for(i=0; i<=n/2; i++)
  {
   pom=pcharni[i];
   pcharni[i]=pcharni[n-i];
   pcharni[n-i]=pom;
  }
 return pcharni; 
}
void charpok()
 {
  char *pass, *pochar[20],ni[20];
  pass=getpass("Enter password:");
  cout<<"pass:"<<pass<<endl;
  cout<<"napisi nesto:";
  cin.getline(ni,20);
  cout<<"Zborot pred invertiranje:"<<ni<<endl;
  cout<<"Invertiran zbor:"<<invertch(ni)<<endl;
  getch();
 }

int main(int argc, char* argv[])
{
char zn;
do
 {
  clrscr();
  cout<<"Izberi opcija:"<<endl;
  cout<<"1.Test integer pointers"<<endl<<"2.Test char pointers"<<endl;
  cout<<"0.Izlez"<<endl;
  zn=getch();
  switch (zn)
   {
    case '1':{intpok();break;}
    case '2':{charpok();break;}
   }
  } 
while (zn!='0');
       return 0;
}

