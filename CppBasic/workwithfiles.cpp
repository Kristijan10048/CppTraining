#pragma hdrstop
# include <iostream.h>
# include <fstream.h>
# include <conio.h>
# include <string.h>
# include <dir.h>
#pragma argsused
void readdat(char path[100]);
void writedat(char path[100]);
void epath();
void appenddat(char path[100]);
void recorddat(char path[100]);

char buf,pt[100];
struct data
{
char ime[30];
int br;
}dat;

void epath()
{
 cout<<"Vnesete ja patekata na datotekata:"<<endl;
 cin>>pt;
}

void readdat(char path[30])
{
 clrscr();
 ifstream f;
  if (!f)
   {cout<<"error"<<endl;}
   else
    {f.open(path,ios::nocreate);}
    f.unsetf(ios::skipws);
    cout<<"Tekstot vo datotekata e:"<<endl;
    cout<<"_________________________________"<<endl;
    while(!f.eof())
     {
      f>>buf;
      cout<<buf;
    }
    cout<<endl;
    cout<<"_________________________________"<<endl;
   getch();
   f.close();
}

void writedat(char path[100])
{
clrscr();
fstream f;
if (!f)
{
 cout<<"Eroor open file"<<path<<endl;
 }
 else
  {
   f.open(path);
   cout<<"Vnesete go tekstot sto sakate da go zapisete vo datotekata:"<<endl;
   cout<<"Za izlez pritisnete Esc"<<endl;
   cout<<"_______________________________________________________________"<<endl;
   do
    {
     buf=getche();
     if (buf=='\r')
       {
        buf='\n';
        cout<<'\n';
       }
      if (buf=='\x1B') break;
       f<<buf;
     }
   while(buf!='\x1B');
  }
}

void appenddat(char path[100])
{
ofstream f;
f.open(path,ios::app);
if (!f) {cout<<"Error"<<endl;}
else
 {
  cout<<"Vnesete go tekstot sto sakate do go dodadete vo datotekata:"<<endl;
  cout<<"Pritisnete Esc za izlez"<<endl;
  cout<<"__________________________________________________________"<<endl;
  do
   {
    buf=getche();
    if (buf=='\x1B')break;
    if (buf=='\r')
     {
      cout<<'\n';
      buf='\n';
     }
    f<<buf;
   }
  while(buf!='\x1B');
 }

}

void recorddat(char path[100])
{
fstream f;
f.open(path);
if (!f)
 { cout<<"Error"<<endl;getch();}
  else
   {
   cout<<"Za izlez pritisnete Esc"<<endl;
   do
    {
     cout<<"Vnesete go imeto"<<endl;
     cin>>dat.ime;
     cout<<"Vnesete go redniot broj"<<endl;
     cin>>dat.br;
     f<<dat.ime;
     f<<dat.br;
    }
    while(buf!='\x1B');
   }
}
int main(int argc, char* argv[])
{
char zn;
do
{
 clrscr();
 cout<<"Izberete opcija"<<endl;
 cout<<"1.Citanje od datoteka"<<endl<<"2.Dodavanje na teks vo postocka datoteka"<<endl;
 cout<<"3.Kreiranje nova datoteka"<<endl;
 cout<<"0.Izlez"<<endl;
 zn=getch();
 switch (zn)
  {
   case '1':
      {
        epath();
        readdat(pt);
        break;
      }
   case '2':
     {
      epath();
      appenddat(pt);
      break;
     }
   case'3':
     {
      epath();
      writedat(pt);
      break;
     }

  case '4':
   {
    epath();
    recorddat(pt);
    break;
   }
  }

}
while (zn!='0');

        return 0;
}

