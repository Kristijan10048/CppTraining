#pragma hdrstop
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#define uint unsigned int

class vrablice
{
 protected:
 uint plata,matbr;
 string ime,prezime;
 public:
 vrablice()
 {
  plata=0;
  matbr=0;
  ime="";
  prezime=" ";
 }
 void inputdat();
 void printdat();
};

void vrablice::inputdat()
{
 clrscr();
 cout<<"Ime:";
 cin>>ime;
 cout<<endl<<"Prezime:";
 cout<<"Plata:";
 cin>>plata;
}

void vrablice::printdat()
{
 cout<<"Ime:"<<ime<<endl;
 cout<<"Prezime:"<<prezime<<endl;
 cout<<"Plata:"<<plata<<endl;
}
//smetkovoditel-------------------------------------------------------------------------

class smetkovoditel:vrablice
{
 char netpas[50];
 char logonnet[10];
 public:
  void inputdat();
  void printdat();
};

void smetkovoditel::inputdat()
{
 clrscr();
 cout<<"Ime:";
 cin>>ime;
 cout<<endl<<"Prezime:";
 cout<<"Plata:";
 cin>>plata;
 cout<<endl<<"NetworkPas:";
 cin>>netpas;
 cout<<"Logon net:";
 cin>>logonnet;
}

void smetkovoditel::printdat()
{
 cout<<"Ime:"<<ime<<endl;
 cout<<"Prezime:"<<prezime<<endl;
 cout<<"Plata:"<<plata<<endl;
 cout<<"NetworkPass:"<<netpas<<endl;
 cout<<"Logon net:"<<logonnet;
}
//ceo----------------------------------------------------------------------
class ceo:vrablice
{
 string adminpas;
 bool adpass;
 void enterpass();
 public:
 void inputdat();
 void printdat();
 ceo()
 {
  adminpas=" ";
  adpass=false;
 }
};

void ceo::inputdat()
{
 clrscr();
 cout<<"Ime:";
 cin>>ime;
 cout<<endl<<"Prezime:";
 cout<<"Plata:";
 cin>>plata;
 enterpass();
}

void ceo::printdat()
{
 cout<<"Ime:"<<ime<<endl;
 cout<<"Prezime:"<<prezime<<endl;
 cout<<"Plata:"<<plata<<endl;
 cout<<"adminpass:"<<adpass<<endl;
 cout<<"pass:"<<adminpas;
}

void ceo::enterpass()
{
 string tempass;
 char pass;
 cout<<"Password:";
 do
  {
   pass=getch();
   cout<<"*";
   tempass+=pass;
  }
 while(pass!='\r');
cout<<"confirm pasword:";
do
  {
   pass=getch();
   cout<<"*";
   adminpas+=pass;
  }
while(pass!='\r');
if(tempass!=adminpas)
{enterpass();}
adpass=true;
}
ceo obj1;
int main(int argc, char* argv[])
{
 obj1.inputdat();
 obj1.printdat();
system("pause");
        return 0;
}
//---------------------------------------------------------------------------
