#pragma hdrstop
#pragma argsused
# include <iostream.h>
# include <conio.h>
void printmatrix(unsigned int ko,unsigned int re,int matr[20][20]);
void sortcolum(unsigned int len);
int colum[20];
typedef int matrix[20][20];



void printmatrix(unsigned int ko,unsigned int re,int matr[20][20])
{
 unsigned int i,j;
 cout<<"Matricata izgleda vaka:"<<endl;
 for(i=0;i<=ko-1;i++)
  {
   for(j=0;j<=re-1;j++)
     cout<<matr[i][j]<<" ";
   cout<<endl;
  }
getch();
}


void sortcolum(unsigned int len)
{
 int j,i,pom;
 for(i=0;i<=len-1;i++)
  for(j=0;j<=len-2;j++)
    if (colum[j]>colum[j+1])
      {
       pom=colum[j];
       colum[j]=colum[j+1];
       colum[j+1]=pom;
      }
}


int main(int argc, char* argv[])
{
matrix mat;
unsigned int kol,red,i,j;
cout<<"Vnesete go brojot na koloni vo matricata"<<endl;
cin>>kol;
cout<<"Vnesete go brojot na redici vo matricata"<<endl;
cin>>red;
for(i=0 ;i<=kol-1;i++)
 for(j=0 ;j<=red-1 ; j++)
  {
   cout<<"Matrix["<<i<<","<<j<<"]=";
   cin>>mat[i][j];
  }
for(i=0 ;i<=kol-1;i++)
 {
  for(j=0 ;j<=red-1 ; j++)
       colum[j]=mat[i][j];
  sortcolum(red);
  for(int k=0;k<=red-1;k++)
   mat[i][k]=colum[k];
  }
printmatrix(kol,red,mat);
getch();
        return 0;
}

