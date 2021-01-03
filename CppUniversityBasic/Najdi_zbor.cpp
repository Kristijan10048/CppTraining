#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void opendat(ifstream &f1);
void opendat(ifstream &f1)
{
 char path[100];
 cout<<"Vnesete ja patekata:";
 cin>>path;
 f1.open(path);
 if(!f1)
  {
   cout<<"Greska";
   system("pause");
  }
}
void printdat(ifstream &f1);
void printdat(ifstream &f1)
{
char buf;
f1.unsetf(ios::skipws);
while(!f1.eof())
 {
  f1>>buf;
  cout<<buf;
 }
system("pause");
f1.close();
}

void charinstr(string &str,char ni[200])
{
 for(int i=0;i<=strlen(ni)-1;i++)
 str+=ni[i];
}
bool sporedi(string s1,string s2)
{
 unsigned int dol,i;
 if(s1.length()!=s2.length())
  return(false);
   else
   {
    dol=s1.length();
    for(i=0;i<=dol-1;i++)
    {
     if(s1[i]!=s2[i])
      return(false);
    }
   }
  return(true);
}
void najdizbor(ifstream &f1);
void najdizbor(ifstream &f1)
{
 char buf,zb[100];
 string pzbor,zbor;
 int i=0,j=0,znaci=0;
 cout<<"Vnesete go zborot sto sakate da go pobarate vo datotekata:";
 cin>>zbor;
 f1.unsetf(ios::skipws);
 while(!f1.eof())
  {
   f1>>buf;
   znaci++;
   if(buf!=' ')
   {
    pzbor+=buf;
    i++;
    if(buf=='\n')
     {
      j++;
      i=0;
   } }
   else
    {
      if(pzbor==zbor)
     cout<<"Zborot"<<pzbor<<" se naoga vo "<<j<<" red na pozicija:"
     <<i-1<<"\n";
     pzbor.clear();

    }
  }
f1.close();
cout<<"Datotekata sodrzi "<<znaci<<" znaci i ima "<<j+1<<" redovi";
system("pause");
}

int main(int argc, char* argv[])
{
ifstream f;
char zn;
do
{
 clrscr();
 cout<<"1.Listanje na sodrzinata na dadena datoteka"
 <<"\n2.Baranje na zbor vo dadena datoteka"<<"\n0.Izlez";
 zn=getch();
 switch(zn)
  {
   case'1':
    {
     clrscr();
     opendat(f);
     printdat(f);
     break;
    }
   case'2':
    {
     clrscr();
     opendat(f);
     najdizbor(f);
    }
  }
 }
while(zn!='0');
        return 0;
}
//---------------------------------------------------------------------------
