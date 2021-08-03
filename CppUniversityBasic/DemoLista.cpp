#ifdef NOT_FIXED
#define NIL 0
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>

struct Lista
 {  // List node header
    int info;
    Lista *sleden;
 };

void Vmetni (Lista **L, int info);
void Brisi (Lista **L, int info);
void PecatiLista (Lista *prv);

main()
{
 Lista *L;
 int broj;
 char izbor;
 L=NIL;
 do
  {
   clrscr();
   cout << "Izberi opcija:\n";
   cout << "1. dodavanje vo lista\n";
   cout << "2. pecatenje na lista\n";
   cout << "3. brisenje na element\n";
   cout << "4. kraj\n\n";
   izbor=getch();
    switch (izbor)
     {
      case '1' :
       {
        cout << "Vnesi go elementot:";
        cin >>broj;
        Vmetni(&L, broj);
        break;
      }
     case '2' :
      {
       cout << "Listata e:" << endl;
       PecatiLista(L);
       system("pause");
       break;
      }
    case '3' :
      {
       cout << "Vnesi go elementot:";
       cin >>broj;
       Brisi(&L, broj);
       break;
      }
    case 4 : break;
    default : cout << "Pogresna vrednost\n";
   }
  }
while (izbor < 4);

   return 0;

}


//---------------------------------------------------------------------------

void Vmetni (Lista** L, int info)
{
 Lista *temp = new Lista;
 temp->info=info;
 temp->sleden=*L;
 *L=temp;
}


void PecatiLista (Lista* prv)
{
  if (prv != NIL)
    {
     cout << prv->info << "->" ;
     PecatiLista (prv->sleden);}
    }
}

void Brisi (Lista **L, int vrednost)
{
 Lista *prethoden = new Lista;
 Lista *nareden = new Lista;
 Lista *temp = new Lista;
 bool najden=false;
  if(*L==NIL)
   {
    cout << "Listata e prazna! \n";
    return;
   }
   prethoden=*L;
   nareden=(*L)->sleden;
   if ((*L)->info==vrednost)
   {
    *L=nareden;
     delete(prethoden);
     najden=true;
   }
  else
   {
    while(prethoden->sleden!=NIL && !najden)
     {
      if (nareden->info==vrednost)
        {
         prethoden->sleden=nareden->sleden;  //temp=prethoden;
         delete(nareden);
         najden=true;
        }
         else
          {
           prethoden=prethoden->sleden;
           nareden=nareden->sleden;
           }

     }
   }
 if(!najden) cout << "Elementot go nema vo listata. \n";
}
#endif