#include <vcl.h>
#pragma hdrstop
#pragma argsused
#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
/*----------car----------------*/
class car
{
 protected:
  float armor,windowarr,wheelarmor,speed;
  public:
  virtual void input();
  virtual void printdat();
  
};

void car::input()
{
 clrscr();
 cout<<"Car armor:";
 cin>>armor;
 cout<<endl<<"Window armor:";
 cin>>windowarr;
 cout<<"Wheels armor:";
 cin>>wheelarmor;
 cout<<endl<<"Speed:";
 cin>>speed;
}

void car::printdat()
{
 cout<<"Car armor:"<<armor<<endl<<"Window armor:"<<windowarr<<endl;
 cout<<"Speed:"<<speed;
}
/*-----------jeep-------------------*/
class jeep:public car
{
  protected:
   char radio[3];
    public:
     void input();
     void printdat();

};

void jeep::input()
{
 clrscr();
 cout<<"Car armor:";
 cin>>armor;
 cout<<endl<<"Window armor:";
 cin>>windowarr;
 cout<<"Wheels armor:";
 cin>>wheelarmor;
 cout<<endl<<"Speed:";
 cin>>speed;
 cout<<endl<<"Radio(ON\OFF)";
 cin>>radio;
}

void jeep::printdat()
{
 cout<<"Car armor:"<<armor<<endl<<"Window armor:"<<windowarr<<endl;
 cout<<"Speed:"<<speed<<"Radio:"<<radio;
}
/*-------------Jeep MG------------*/
class jeepmg:public car
{
 char mgun[10];
 float cal;
  public:
   void input();
   void printdat();

};

void jeepmg::input()
{
 clrscr();
 cout<<"Car armor:";
 cin>>armor;
 cout<<endl<<"Window armor:";
 cin>>windowarr;
 cout<<"Wheels armor:";
 cin>>wheelarmor;
 cout<<endl<<"Speed:";
 cin>>speed;
 cout<<"MachineGan:";
 cin>>mgun;
 cout<<endl<<"Calibar:";
 cin>>cal;
}

void jeepmg::printdat()
{
 cout<<"Car armor:"<<armor<<endl<<"Window armor:"<<windowarr<<endl;
 cout<<"Speed:"<<speed<<endl<<"MachineGan:"<<mgun<<endl;
 cout<<"Calibar:"<<cal;
}
void vnesiobj(car&);
void pecatiobj(car&);

void pecatiobj(car & ob)
{
 ob.printdat();
}

void inputinlist(car & obj);
car niza[10];
int i=0;
void inputinlistcar(car & obj)
{
 niza[i]=obj;
 i++;
}

void printlistcar();
void printlistcar()
{
int j;
for(j=0;j<=i-1;j++)
{
 niza[j].printdat();
 cout<<endl<<"----------------------------------------------"<<endl;
}
system("pause");
}

jeep nizajeep[10];
int k=0;
void inputlistjeep(jeep & obj);
void inputlistjeep(jeep & obj)
{
 nizajeep[k]=obj;
 k++;
}

void printlistjeep();
void printlistjeep()
{
 int j;
for(j=0;j<=k-1;j++)
 {
  nizajeep[j].printdat();
  cout<<endl<<"----------------------------------------"<<endl;
 }
system("pause");
}

int main(int argc, char* argv[])
{
car obj1;
jeep obj2;
jeepmg obj3;
/*
cout<<"For car"<<endl;
system("pause");
obj1.input();
cout<<"For jeep"<<endl;
system("pause");
obj2.input();
cout<<"For JeepMG"<<endl;
system("pause");
obj3.input();
system("pause");
cout<<"Print car"<<endl;
pecatiobj(obj1);
cout<<"Print jeep"<<endl;
pecatiobj(obj2);
cout<<"Print JeepMG"<<endl;
pecatiobj(obj3);
*/
char zn;
do
{
 clrscr();
 cout<<"1.Dodavanje na car"<<endl
 <<"2.Dodavanje na jeep"<<endl
 <<"3.dodavanje na JeepMG"<<endl
 <<"4.pecatenje na listata na car"<<endl
 <<"5.pecatenje na listate jeep"<<endl;
 zn=getch();
 switch(zn)
 {
   case '1':
    {
     obj1.input();
     inputinlistcar(obj1);
     break;
    }
    case '2':
     {
      obj2.input();
      inputlistjeep(obj2);
      break;
     }
    case '3':
     {
      /*
      obj3.input();
      inputlistjeep(obj3);
      break;
      */
     }
    case '4':
     {
      printlistcar();
      break;
     }
    case '5':
    {
     printlistjeep();
    }
 }
}
while(zn!='0');
system("pause");
        return 0;
}

