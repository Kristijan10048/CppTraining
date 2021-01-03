# include <iostream.h>
# include <conio.h>
# include <dos.h>
# include <string.h>
# include <stdlib.h>
#pragma hdrstop
#pragma argsused
class car
{
 private:
  string mark;
  unsigned int year,hp,carpr;
 public:
 virtual void calcprice();
 virtual void inpbasicprop()
   {
    cout<<"Enter mark:";
    cin>>mark;
    cout<<endl<<"Enter year of production:";
    cin>>year;
    cout<<endl<<"Enter horsepower:";
    cin>>hp;
    }
  void printbasicprop()
   {
    cout<<"Mark:"<<mark<<endl;
    cout<<"Production year:"<<year<<endl;
    cout<<"Horsepower:"<<hp<<endl;
   }
   car()
    {
     cout<<"car start"<<endl;
    }
  ~car()
   {
    cout<<"Bye-Bye car"<<endl;
   }
};
class jeep:public car
{
 private:
  unsigned int weight,maxsp,maxload;
   string engine,origin,armor,ammo,gun;
 public:
  void armed();
  void printarm();
  void changeprop(jeep& obj);
  friend bool changedat();
  void inpjeepprop()
   {
    inpbasicprop();
    cout<<"Enter jeep weight:";
    cin>>weight;
    cout<<endl<<"Enter jeep maxsimum load:";
    cin>>maxload;
    cout<<endl<<"Enter jeep engine type:";
    cin>>engine;
    cout<<endl<<"Enter jeep origine:"<<endl;
    cin>>origin;
   }
  void printjeeppror()
   {
    printbasicprop();
    cout<<"Jeep weight:"<<weight<<endl;
    cout<<"jeep maxsimum load:"<<maxload<<endl;
    cout<<"Jeep engine type:"<<engine<<endl;
    cout<<"Jeep origine:"<<origin<<endl;
    printarm();
   }
   jeep()
    {
     cout<<"Jeep start"<<endl;
    }
   ~jeep()
     {
      cout<<"Bye-bye jeep"<<endl;
     }
};

void car::calcprice()
{
 cout<<"Enter car price:";
 cin>>carpr;
 cout<<"Car prise with tax:"<<carpr+(19*carpr/100);
}

void jeep::armed()
{
 cout<<"jeep armor:";
 cin>>armor;
 cout<<endl<<"Jeep machinegun:";
 cin>>gun;
 cout<<endl<<"Jeep ammo:";
 cin>>ammo;
}

void jeep::printarm()
 {
  cout<<"Jeep armor:"<<armor<<endl;
  cout<<"Jeep machinegun:"<<gun<<endl;
  cout<<"Jeep ammo:"<<ammo<<endl;
 }

void jeep::changeprop(jeep& obj)
 {
   char zn;
 do
 {
  cout<<"Pick option:"<<endl;
  cout<<"1.Change car basic prop"<<endl;
  cout<<"2.Change car armor:"<<endl;
  zn=getch();
   switch(zn)
    case '1':
           {
            if (changedat()==true)
            {obj.inpbasicprop();}
             else break;
           }
 }
 while(zn!='0');
 }

void inputinlist(car & obj);
car niza[10];
int i=0;
void inputinlist(car & obj)
{
 niza[i]=obj;
 i++;
}

void printlist();
{
int j;
for(j=0j<=i-1;j++)
 niza[j].
}
inline bool changedat()
{
 char zn;
 cout<<"Are you sure you want to change data?(Y/N)";
 zn=getch();
 zn=toupper(zn);
 if(zn='Y')
    {return true;}
    else return false;
}

int main(int argc, char* argv[])
{
jeep vehicle;/*
vehicle.inpjeepprop();
vehicle.calcprice();
vehicle.armed();
cout<<"Jeep arm:"<<endl;
vehicle.printjeeppror();
cout<<"Change dat"<<endl;
*/
car c;
vehicle.changeprop(vehicle);
char zn;
do
{
 cout<<"1.Dodavanmje na car"<<ednl;
 cout<<"2.Dodavanje na jeep"<<endl;
 zn=getch();
 switch(zn)
  {
   case '1':
    {
     c.inpbasicprop();
     inputinlist();
    }
  }
}
while(an!='0');
getch();
      return 0;
}

