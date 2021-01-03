#pragma hdrstop
#pragma argsused
# include <iostream.h>
# include <conio.h>
# include <string.h>
class account
{
 private:
  int accountnumb,pin,cash;
  char check;
  public:
  friend void dodadipar(account &,int);
  friend void zvadipar();
  void inpdat();
  void printdat();
};

void account::inpdat()
{
 cout<<"Accocount number:";
 cin>>accountnumb;
 cout<<endl<<"Pin:";
 cin>>pin;
 cout<<endl<<"Cash:";
 cin>>cash;
 cout<<"Checks(Y/N):";
 cin>>check;
}

void account::printdat()
{
 cout<<"Accocount number:"<<accountnumb<<endl;
 cout<<"Pin:"<<pin<<endl<<"Cash:"<<cash<<"Checks:"<<check<<endl;
}

class human
{
 private:

  string ime,prezime,adresa;
  account ac;
  char pol,vraboten,vobr;
 public:
  void inpdat();
  void printdat();
  void changedat();
  friend void changeaccval(human&);
  inline bool sure();
  
} ;



void human::inpdat()
{
 cout<<"Name:";
 cin>>ime;
 cout<<"\nLastname:";
 cin>>prezime;
 cout<<"\nAddress:";
 cin>>adresa;
 cout<<"Sex(M/F):";
 cin>>pol;
 cout<<"Eployed(Y/N):";
 cin>>vraboten;
 cout<<"Married(Y/N):";
 cin>>vobr;
 ac.inpdat();
};



void human::printdat()
{
  char ch;
  cout<<"Name:"<<ime<<endl<<"Lastname:"<<prezime<<endl;
  cout<<"Address:"<<adresa<<endl<<"Sex:"<<pol<<endl;
  cout<<"Employed:"<<vraboten<<endl<<"Married:"<<vobr<<endl;
  cout<<"Would you like to print accunt?(Y/N)";
  ch=getch();
  ch=toupper(ch);
  if(ch=='Y')
   {
    ac.printdat();
   }
  cout<<"Press eny key to continue";getch();
}

void human::changedat()
{
 char zn;
 do
 {
  cout<<"Choose option:"<<endl;
  cout<<"1.Change name\n";
  cout<<"2.Change Lastneme\n";
  cout<<"0.Exit";
  switch (zn)
   {
   case '1':
         { if (sure()==true)
          {
           cout<<"Name:";
           cin>>ime;
          }
          break;
         }
   case '2':
         {
          if(sure()==true)
           {
            cout<<"Lname:";
            cin>>prezime;
           }
          break;
         }
    }
 }
 while(zn!='0');
}


bool sure()
{
 char b;
 cout<<"Are you sure you want to make change?(Y/N)";
 b=getch();
 b=toupper(b);
 if (b=='Y'){return true;}
  else return false;
}

void dodadipar(account & cas,int ca)
{
 cas.cash+=ca;
}
void changeaccval(human &hu)
{
 int c;
 cout<<"Enter cash:";
 cin>>c;
 dodadipar(hu.ac,c);
}
int main(int argc, char* argv[])
{
human obj1;
obj1.inpdat();
obj1.printdat();
cout<<"Promena na sostojba"<<endl;
changeaccval(obj1);
cout<<"Posle dodavanje na cash"<<endl;
obj1.printdat();
getch();
        return 0;
}

