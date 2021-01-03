#include <conio.h>
#include<stdlib.h>
#include<iostream.h>

class mychar
{
 char temp[100];
 public:
 int dolzina()
  { return(strlen(temp));}

 void vnesi()
 {cin>>temp;}

 void pecati()
 {cout<<temp;}

  void clear()
 { temp[0]='\0';}

 char operator[](int i)
 { return(temp[i]);}


  mychar operator=(mychar tmp)
  {
   for(int i=0;i<=tmp.dolzina();i++)
    {
     temp[i]=tmp[i];
    }
  }

};


/*------------VRABOTEN START----------------*/
class vraboten
{
 protected:
  mychar ime;
  int br;
  public:
  vraboten()
  {
   ime.clear();
   br=0;
  }
  vraboten(mychar i,int b=0)
  {
   ime=i;
   br=b;
  }
  virtual void postavi();
  virtual void prikazi();
  vraboten operator=(vraboten temp)
  {
   ime=temp.ime;
   br=temp.br;
  }
};
void vraboten::postavi()
{
cout<<"Ime:";
ime.vnesi();
cout<<endl<<"Broj:";
cin>>br;
}

void vraboten::prikazi()
{
 cout<<"Ime:";
 ime.pecati();
 cout<<endl<<"Broj:"<<br<<endl;
}
/*---------------------VRABOTEN END--------------*/

/*---------PROFESOR START----------*/
class profesor:vraboten
{
 mychar oblast;
 public:
  virtual void postavi();
  virtual void prikazi();
  profesor()
  {
   ime.clear();
   br=0;
   oblast.clear();
  }
};
void profesor::postavi()
{
cout<<"Ime:";
ime.vnesi();
cout<<endl<<"Broj:";
cin>>br;
cout<<endl<<"Oblast:";
oblast.pecati();
}

void profesor::prikazi()
{
 cout<<"Ime:";
 ime.pecati();
 cout<<endl<<"Broj:"<<br<<endl<<"Oblast:";
  oblast.pecati();
}

/*----------------Profesor END-----------------*/

/*---------------ASISTENT START----------------*/
class asistent:vraboten
{
 mychar ment;
  public:
   asistent()
   {
    br=0;
    ment.clear();
    ime.clear();
   }
  virtual void postavi();
  virtual void prikazi();

};

void asistent::postavi()
{
cout<<"Ime:";
ime.vnesi();
cout<<endl<<"Broj:";
cin>>br;
cout<<endl<<"Mentor:";
ment.vnesi();
}

void asistent::prikazi()
{
 cout<<"Ime:";
 ime.pecati();
 cout<<endl<<"Broj:"<<br<<endl<<"Mentor:";
 ment.pecati();
}

int main(int argc, char* argv[])
{
        return 0;
}
//---------------------------------------------------------------------------
