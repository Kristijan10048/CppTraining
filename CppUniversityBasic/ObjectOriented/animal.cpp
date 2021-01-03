#pragma hdrstop
#pragma argsused
# include <iostream.h>
# include <conio.h>
# include <string.h>

class animal
{
 private:
  int godnarag;
  char pol;
  char ime[50];
 public:
 void inputdat();
 void printdat();
 virtual void vakcinacija();
};
void animal::inputdat()
{
 cout<<"Godina na raganje:";
 cin>>godnarag;
 cout<<endl<<"Ime:";
 cin>>ime;
 cout<<endl<<"Pol:";
 cin>>pol;
}

void animal::printdat()
{
 cout<<"Godina na raganje:"<<godnarag<<endl;
 cout<<"Ime:"<<ime<<endl;
 cout<<"Pol:"<<pol;
}

void animal::vakcinacija()
{
 cout<<"Vakcinacijata varira (osnovna kl)"<<endl;
}

class ptici:public animal
{

  public:
   void vakcinacija();
};

void ptici::vakcinacija()
{
 cout<<"Vakcinacija sa pravi na sekoi 6meseci (izvedena klasa ptici)"<<endl;
}

class vlekaci:public animal
{
 public:
  void vakcinacija();
};

void vlekaci::vakcinacija()
{
 cout<<"Vakcinacijata e promenliva (izv klasa vlakaci)"<<endl;
}

class cicaci:public animal
{
 public:
 void vakcinacija();
};

void cicaci::vakcinacija()
{
 cout<<"Vakcinaciata e ednas godisno (izv klasa cicaci)"<<endl;
}


int main(int argc, char* argv[])
{
animal obj;
ptici  pti;
cicaci cic;
vlekaci vle;
obj.inputdat();
obj.printdat();
obj.vakcinacija();
cout<<"Podatoci za ptici:"<<endl;
pti.inputdat();
pti.printdat();
pti.vakcinacija();
cout<<"Podatoci za cicaci:"<<endl;
cic.inputdat();
cic.printdat();
cic.vakcinacija();
cout<<"Podatoci za vlekaci"<<endl;
vle.inputdat();
vle.printdat();
vle.vakcinacija();
obj=vle;
cout<<"obj=vle:"<<endl;
obj.printdat();
obj.vakcinacija();
getch();
        return 0;
}

