#include<iostream.h>
#include<conio.h>
#include <stdlib.h>
# define UINT unsigned int

void inputelementuci();
void printelementucil();

class pro
{
protected:
 UINT br,povrsina,spr;
   public:
   UINT returnprovrsina()
    {return povrsina;}
   virtual void vnesipod();
   virtual void printpod();
 pro()
  {
   br=0;
   povrsina=0;
   spr=0;
  }
};

void pro::vnesipod()
{
 clrscr();
 cout<<"Broj:";
 cin>>br;
 cout<<"\nPovrsina:";
 cin>>povrsina;
 cout<<"Sprat:";
 cin>>spr;

}
void pro::printpod()
{
 cout<<"Broj:"<<br<<endl;
 cout<<"Sprat:"<<spr<<endl;
 cout<<"Povrsina:"<<povrsina<<endl;
}
//-----------------------------------------------------------
class ucil:pro
{
 friend int presmetajpovrsina();
 char namena[30];
 public:
  void vnesipod();
  void printpod();
};

void ucil::vnesipod()
{
 clrscr();
 cout<<"Broj:";
 cin>>br;
 cout<<"\nPovrsina:";
 cin>>povrsina;
 cout<<"Sprat:";
 cin>>spr;
 cout<<"Namena:";
 cin>>namena;
}

void ucil::printpod()
{
 cout<<"Broj:"<<br<<endl;
 cout<<"Sprat:"<<spr<<endl;
 cout<<"Povrsina:"<<povrsina<<endl;
 cout<<"Namena:"<<namena<<endl;
}
//--------UCIL------------------------------------------
class lab:pro
{
 friend int presmetajpovrsina(lab);
 UINT brnakomp;
 public:
  void vnesipod();
  void printpod();
};


void lab::vnesipod()
{
 clrscr();
 cout<<"Broj:";
 cin>>br;
 cout<<"\nPovrsina:";
 cin>>povrsina;
 cout<<"Sprat:";
 cin>>spr;
 cout<<"Broj na kompjuteri:";
 cin>>brnakomp;
 if (!cin)
  {
   cin.clear();
   cin>>brnakomp;
  }

}

void lab::printpod()
{
 cout<<"Broj:"<<br<<endl;
 cout<<"Sprat:"<<spr<<endl;
 cout<<"Povrsina:"<<povrsina<<endl;
 cout<<"Broj na kompjuteri:"<<brnakomp<<endl;
}
//---LAB------------------------------------------


ucil obj2[30];
lab obj1[30];
UINT nu,nlab=0;

void inputelementuci()
{
 int i=0;
 char zn;
 zn='D';
 while(zn=='D')
   {
    obj2[i].vnesipod();
    cout<<"Dali sakate da vnesuvate uste?(D|N)"<<endl;
    zn=getch();
    zn=toupper(zn);
    i++;
    nu+=1;
  }

}
int presmetajpovrsina()
{
 int i=0;
 UINT povrs=0;
 for(i=0;i<=nu;i++)
  {
    povrs=povrs+obj2[i].returnprovrsina();
  }
 return(povrs);
}

void printelmetsuci()
{
 clrscr();
 int i;
 for(i=0;i<=nu;i++)
  {
   cout<<"--------------------------------------------------------------"<<endl;
   obj2[i].printpod();
  }
 cout<<"Vkupnata povrsina iznesuva:"<<presmetajpovrsina()<<endl;
 system("pause");
}

void inputelementlab()
{
 int i=0;
 char zn;
 zn='D';
 while(zn=='D')
   {
    obj1[i].vnesipod();
    cout<<"Dali sakate da vnesuvate uste?(D|N)"<<endl;
    zn=getch();
    zn=toupper(zn);
    i++;
    nlab+=1;
  }
}

void printelementlab()
{
 clrscr();
 int i;
if(nlab!=0)
{
 for(i=0;i<=nlab-1;i++)
  {
   cout<<"--------------------------------------------------------------"<<endl;
   obj1[i].printpod();
  }
 }
 system("pause");
}

int main(int argc, char* argv[])

{
 char zn;
 do
  {
  clrscr();
  cout<<"Izberete opcija:"<<endl;
  cout<<"1.Dodavanje na objekti na uculnica:"<<endl;
  cout<<"2.Dodavanje na objekti na lab:"<<endl;
  cout<<"3.Pecatenje na podaticite za ucilnicite:"<<endl;
  cout<<"4.Pecatenje na podatocite za labaratorii:"<<endl;
  cout<<"0.Izlez"<<endl;
  zn=getch();
  switch (zn)
   {
    case '1':
      {
       inputelementuci();
        break;
      }
    case '2':
     {
      inputelementlab();
      break;
     }
    case '3':
     {
      printelmetsuci();
      break;
     }
    case '4':
     {
      printelementlab();
      break;
     }
   }
 }
 while(zn!='0');
        return 0;
}

