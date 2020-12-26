#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#define uint unsigned int
uint matrix[8][8],kol,red;
uint* vnmatrix();
uint* vnmatrix()
{
 int i,j;
 uint mat[8][8];
 cout<<"Koloni:";
 cin>>kol;
 cout<<endl<<"Redici:";
 cin>>red;
 for(i=0;i<=kol-1;i++)
  for(j=0;j<=red-1;j++)
  {
   cout<<"mat["<<i<<"-"<<j<<"]=";
   cin>>mat[i][j];
  }
return(*mat);
}

void transponemat();
void transponemat()
{
 uint i,j,mat[8][8],pom;
 for(j=0;j<=red-1;j++)
  for(i=0;i<=kol-1;i++)
  {
   mat[j][i]=matrix[i][j];
  }
pom=kol;
kol=red;
red=pom;
for(i=0;i<=kol-1;i++)
 for(j=0;j<=red-1;j++)
  matrix[i][j]=mat[i][j];
}

void printmatrix();
void printmatrix()
{
int i,j;
 for(i=0;i<=kol-1;i++)
 {
  for(j=0;j<=red-1;j++)
   cout<<matrix[i][j]<<" ";
  cout<<endl;
 }
}

int main(int argc, char* argv[])
{
char zn;
do
{
 cout<<"1.Transponiranje na matrica"<<endl;
 cout<<"2.Mnozenje na dve matrici"<<endl;
 cout<<"0.Izlez"<<endl;
 zn=getch();
  switch(zn)
  {
   case '1':
    {
     matrix=vnmatrix();
     cout<<"Ja vnesovte mztricata:"<<endl;
     printmatrix();
     transponemat();
     cout<<"Transponiranata matrica izgeda caka:"<<endl;
     printmatrix();
    }
   case '2':
    {

    }
  }
}
while(zn!='0');
system("pause");
        return 0;
}
//---------------------------------------------------------------------------
