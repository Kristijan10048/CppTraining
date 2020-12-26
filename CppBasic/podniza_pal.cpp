#include<iostream.h>
#include<conio.h>
int niza[50],n;
bool palindrom(int ni[100],int dol);
bool palindrom(int ni[100],int dol)
{
bool pal=true;
for(int i=0;i<=(dol-1)/2;i++)
 if(ni[i]!=ni[dol-i])
  pal=false;
 return(pal);
}

void najdipodnizi()
{
 int i,j,k,pni[20],z;
 k=1;
 while(k!=n)
 {
  for(i=0;i<=n-k-1;i++)
  {
   z=0;
   for(j=i;j<=i+k;j++)
    {
    pni[z]=niza[j];
    cout<<niza[j];
    z++;
    }
   cout<<"\n"<<"----------"<<endl;
   if( palindrom(pni,k)==true)
    {
     cout<<"palindrom:";
     for(int c=0;c<=k;c++)
      cout<<pni[c];
     cout<<endl; 
    }
  }
  k++;
 }
}

int main(int argc, char* argv[])
{
int i;
cout<<"Broj na elementi:";
cin>>n;
for(i=0;i<=n-1;i++)
 {
  cout<<"N["<<i<<"]=";
  cin>>niza[i];
  cout<<endl;
 }
najdipodnizi();
system("pause");

        return 0;
}
//---------------------------------------------------------------------------
 