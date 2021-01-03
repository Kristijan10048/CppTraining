

#include <vcl.h>
#include <iostream.h>
#pragma hdrstop
#pragma argsused

void vnesiniza(void);
void printn(void);
void reduce(void);

int a[30],i,j,n;
bool red;

void vnesiniza(void)
 {
  cout<<"Kolku clenovi ima nizata:";
  cin>>n;
  for (i=0; i<=n-1; i++)
    {
    cout<<"a["<<i<<"]=";
    cin>>a[i];
    }
 }


void printn(void)
 {
 if (red==false)  { cout<<"Nizata pred redukcijata izgleda vaka \n"<<endl; }
   else {cout<<"Nizata posle redukcijata izgleda vaka\n";}
 for (i=0; i<=n-1; i++)
   cout<<a[i]<<" ";
  cout<<endl;
 }

void reduce(void)
 {
 int k;
 j=0;
 for (i=0; i<=n-1 ; i++)
  for (j=i+1;j<=n-2; j++)
   {
    if (a[i]==a[j])
      {
       for ( k=j; k<=n-2; k++)
         a[k]=a[k+1];
       n=n-1;
       }
   }

 }

int main(int argc, char* argv[])
{
vnesiniza();
red=false;
printn();
red=true;
reduce();
printn();
int g ;
cin>>g;
        return 0;
}

