#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
#define nil 0
struct lista
{
 int info;
 lista *sleden;
};


lista *tek,*ank,*sled;
void vmetni ();
void vmetni ()
{
 clrscr();
 tek=new lista;
 cout<<"\nbroj";
 cin>>tek->info;
 tek->sleden=nil;
 if(ank==nil)
   ank=tek;
  else
  {
   sled=new lista;
   sled=ank;
    while(sled->sleden!=nil)
    {
    sled=sled->sleden;
    }
   sled->sleden=tek;
  }
}

void izbrisiprvel();
void izbrisiprvel()
{
 if(ank==nil)
  {
   cout<<"Listata e prazna";
   system("pause");
   return;
  }
 lista *temp=new lista;
 temp=ank;
 ank=ank->sleden;
 delete(temp);
 cout<<"Go izbrisavte prviot element"<<endl;
 system("pause");
}
void pecatilista(lista* prv);
void pecatilista(lista* prv)
{
 if (prv != nil)
  {
   cout<<prv->info << "->" ;
   pecatilista (prv->sleden);
   }

}

void izbrisiposleden();
void izbrisiposleden()
{
 if(ank==nil)
  {
   cout<<"Listata e prazna";
   system("pause");
   return;
  }
 lista *temp=new lista;
 lista *temp1;
 temp=ank;
 while(temp->sleden!=nil)
 {
  temp1=temp;
  temp=temp->sleden;
  }
 delete(temp);
 temp1->sleden=nil;
 cout<<"Go izbrisavte posledniot element"<<endl;
 system("pause");
}


void izbrisiel();
void izbrisiel()
{
 lista *temp,*temp1,*tek1;
 tek1=new lista;
 temp=ank;
 int br;
 cout<<"Vnesete go elementot sto sakate da go izbrisete:";
 cin>>br;
 while(temp->sleden!=nil)
  {
   tek1=temp;
   temp=temp->sleden;

   if(temp->info==br)
    {
      tek1->sleden=temp->sleden;
    }
  }
cout<<"Go izbrisavte elementot"<<endl;
system("pause");
}

void vnesinapocetok();
void vnesinapocetok()
{
 lista *temp,*tek1;
 int br;
 cout<<"Vnesete go brojot stosakate da govmetnete";
 cin>>br;
 tek=ank;
 temp=new lista;
 temp->info=br;
 ank=temp;
 temp->sleden=tek;
}

void vnesnael();
void vnesnael()
{
 int pos,i=1;
cout<<"Na koe mesto sakate da go vmetnete elementot:";
cin>>pos;
lista *temp,*tek1,*temp1;
tek1=new lista;
tek1=ank;
while(tek1->sleden!=nil)
 {
  temp=tek1;
  tek1=tek1->sleden;
  if(pos==i)
   {
    temp1=new lista;
    cout<<"Vnesete go brojt:";
    cin>>temp1->info;
    temp->sleden=temp1;
    temp1->sleden=tek1;
   }
  i++;
 }
}

int main()
{

ank=nil;
int br;
char zn,izb;
do
{
 clrscr();
 cout<<"1.Vnesuvanje na element"
 <<endl<<"2.Pecatenje na listata"<<endl
 <<"3.Brisenje na prviot element od listata"<<endl
 <<"4.Brisenje na posledniot element od listata"<<endl
 <<"5.Brisenje na daden element od listata"<<endl
 <<"6.Vnesuvanje na element na prvo mesto vo listata"<<endl
 <<"7.Vnesuvanje na element na dadeno mesto vo listata"<<endl
 <<"0.Izlez"<<endl;
 izb=getch();
 switch(izb)
  {
   case '1':
    {
     zn='D';
     while(zn=='D')
     {
      vmetni();
      cout<<"Dali sakas uste da vnesuvas?D/N";
      zn=getch();
      zn=toupper(zn);
     }
     break;
    }
   case '2':
    {
     pecatilista(ank);
     system("pause");
     break;
    }
   case '3':
    {
     izbrisiprvel();
     break;
    }
   case '4':
    {
     izbrisiposleden();
     break;
    }
  case '5':
   {
    izbrisiel();
    break;
   }
  case '6':
   {
    vnesinapocetok();
    break;
   }
  case '7':
   {
    vnesnael();
    break;
   }
  }
}
while(izb!='0');
system("pause");
        return 0;
}

