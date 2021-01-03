# include <iostream.h>
# include <fstream.h>
# include <conio.h>
# include <dos.h>
# include <string.h>
#pragma hdrstop
#pragma argsused
void appdat(char path[40]);
void newdat(char path[40]);
void wordindat(char path[40]);
void vnpath();

char pt[40];
void vnpath()
{
 clrscr();
 cout<<"Vnesete ja patekata na datotekata :"<<endl;
 cin>>pt;

}

void newdat(char path[40])
{
fstream f;
f.open(path);
if (!f){cout<<"Error"<<endl; }
 else
  {
   cout<<"Uspesno e kreirana dadotekata";
  }
 cout<<"Pritisnete bilo koj taster za da prodolzite";
 f.close();
 getch();
}

void appdat(char path[40])
{
char buf;
fstream f;
f.open(path,ios::app);
if (!f) {cout<<"Error";}
 else
  {
   cout<<"Vnesete go tekstot sto sakate da go dodadete vo datotekata"<<endl;
   cout<<"Za izlez pritisnete Esc"<<endl;
   do
   {
    buf=getche();
    if (buf=='\r')
      {
       buf='\n';
       cout<<endl;
      }
    if (buf=='\x1B'){ break;}
    f<<buf;
   }
   while(buf!='\x1B');
  }
}

void wordindat(char path[40])
{
 int red=1,i=0;
 char buf;
 string zbor,inpzb;
 ifstream f;
 f.open(path);
 if (!f) {cout<<"Error";}
  else
   {
    f.unsetf(ios::skipws);
   cout<<"Vnesete go zborot sto sakate do go barate vo datotekata:";
   cin>>inpzb;
    do
    {
     f>>buf;
     if (buf!='\n')
       {
         if (buf!=' ')
          { zbor.operator +=(buf); }
            else
            {
             if (zbor.compare(inpzb)==0)
               {
                cout<<"Zborot '"<<inpzb<<"' se naoga vo "<<red<<" red";
                cout<<" na pozicija "<<i-zbor.length()<<endl;
                }
            zbor.clear();
            }
       i++;
       }
      else
      {red=red+1;i=1;}
    }
    while(!f.eof());
   }

getch();
}

int main(int argc, char* argv[])
{
char zn;
do
{
 clrscr();
 cout<<"Izberete opcija:"<<endl;
 cout<<"1.Kreiranje na nova datoteka"<<endl;
 cout<<"2.Otvaranje na postoecka datoteka i dodavanje na tekst"<<endl;
 cout<<"3.Otvoranje na postoecka datoteka i baranje na daden zbor"<<endl;
 cout<<"0.Izlez"<<endl;
 zn=getch();
 switch (zn)
  {
   case '1':
     {
      vnpath();
      newdat(pt);
     }
   case '2':
     {
      vnpath();
      appdat(pt);
     }
   case '3':
     {
      vnpath();
      wordindat(pt);
     }
  }
}
while(zn!='0');

        return 0;
}

