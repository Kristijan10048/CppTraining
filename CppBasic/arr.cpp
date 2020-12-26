
#include <vcl.h>
#include<iostream.h>
#pragma hdrstop
#pragma argsused

void printk(void);
void vnesimat(void);
void delredica(void);
void delkol(void);


int mat[30][30],i,j,n,m,kred,kkol;
bool br;


void printmat(void)
 {
   if (br==true)
    {cout<<"Matricata pred brisenjeto na redica i kolona izgleda vaka:\n";}
    else
     {cout<<"Matricata posle brisenjeto na redicata i kolonata izgleda vaka:\n";};
       for(int i=1; i<=n; i++)
        {
          for (int j=1; j<=m; j++)
             {
             cout<<mat[i][j]<<" ";
             }
          cout<<"\n";
         }
  }

void vnesimat(void)
 {
 cout<<"Kolku koloni  ima matricata\n";
 cin>>n;
 cout<<"Kolku  redici ima matricata";
 cin>>m;
 for(i=1;i<=n; i++)
   for(j=1; j<=m; j++)
     {
     cout<<"mat["<<i<<"]"<<"["<<j<<"]";
     cin>>mat[i][j];
    }
 }

void delredica(void)
 {
 cout<<"Koja redica sakas da ja izbirises";
 cin>>kred;
if (kred<n)
  {
   for (i=kred; i<=n-1; i++)
    for (j=1; j<=m; j++)
     {
      mat[i][j]=mat[i+1][j] ;
     }
    n=n-1;
    }
  else {n=n-1;}
 }


void delkol(void)
 {
 cout<<"koja kolona sakas da ja izbrises";
 cin>>kkol;
 if (kkol<m)
  {
    for (i=kkol; i<=n; i++ )
      {
       for (j=1; j<=m; j++)
         {
          mat[j][i]=mat[j][i+1];
         }
       }
  m=m-1;
  }
   else {m=m-1;}
 }
int main(int argc, char* argv[])
{
vnesimat();
br=true;
printmat();
br=false;
delkol();
printmat();
delredica();
printmat();
int g;
cin>>g;
        return 0;
}

