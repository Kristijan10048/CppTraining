#include <vcl.h>
#include <iostream.h>
#include <stdlib.h>
void inputmat();
void extendmatr();
int mat[100][100],dkol,dred,kol,red,brprev;


void inputmat()
{
 cout<<"Redici:"<<endl;
 cin>>dred;
 cout<<"\nKoloni:";
 cin>>dkol;
 kol=dkol-1;
 red=dred-1;
 int i,j;
 for(i=0;i<=kol;i++)
  for(j=0;j<=red;j++)
   {
    cout<<"mat["<<i<<j<<"]=";
    cin>>mat[i][j];
   }
}

void printmat()
{
 int i,j;
 for(i=0;i<=kol;i++)
  {
   for(j=0;j<=red;j++)
    cout<<mat[i][j];
   cout<<endl;
  }
}


void extendmatr()
{
 int i,j,k;
  for(i=0;i<=kol;i++)
  {
    k=0;
    for(j=red;j>=0;j--)
     {
      mat[i][((2*dred)-1)-j]=mat[i][k];
      k++;
     }
  }
red=2*red+1;
dred=2*dred;
}
void extendmatd()
{
 int i,j,k;
   for(j=0;j<=red;j++)
   {
    k=0;
    for(i=kol;i>=0;i--)
     {
      mat[((2*dkol)-1)-i][j]=mat[k][j];
      k++;
     }
   }
kol=2*kol+1;
dkol=2*dkol;
}

void rekpati(int pati)
{
for (int i=1;i<=pati;i++)
 {
  extendmatr();
  extendmatd();
 } 
}

int main()
{
inputmat();
cout<<"Kolku pati da se zgolemi:"<<endl;
cin>>brprev;
cout<<"Rered prosiruvanje"<<endl;
printmat();
cout<<"Posle prosiruvanje:"<<endl;
rekpati(brprev);
printmat();
system("pause");
        return 0;
}

