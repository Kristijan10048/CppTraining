
#pragma hdrstop
#pragma argsused
#include <iostream.h>
void vnesi();
void printstr();
void povtoruvanja(int clen);
void sortstr();




struct pojavuvanja
{
int broj,pati;
   void printstr()
     {
     cout<<"Br."<<broj<<" Pati"<<pati<<endl;
     }
}element[50],pelement;

int a[50],b[50];
int i,j,k,n,n1,h,maxp;



void vnesi()
{
cout<<"Kollku clenovi ima nizata:";
cin>>n;
n1=n;
for (i=1;i<=n;i++)
  {
  cout<<"A["<<i<<"]=";
  cin>>a[i];
  }
}

void printstr()
{
cout<<"Nizata posle sortiranjeto izgleda vaka:";
for (i=1; i<=n;i++)
cout<<element[i].broj<<"  ";
}

void povtoruvanja(int clen)
{
element[h].broj=clen;
 for (k=1;k<=n;k++)
  {
   if (a[k]==clen)
    {
    element[h].pati=element[h].pati+1;
    }
   }
}

void sortstr()
{
int i3;
int j3;
for (i3=1;i3<=n*n*n;i3++)
  for (j3=1;j3<=n-1; j3++)
    {
     if (element[j3].pati<element[j3+1].pati)
       {
        pelement=element[j3];
        element[j3]=element[j3+1];
        element[j3+1]=pelement;
       }
    }


for ( i3=1;i3<=n*n*n;i3++)
  for (j3=1;j3<=n-1; j3++)
    {
     if ((element[j3].pati==element[j3+1].pati) && (element[j3].broj!=element[j3+1].broj))
        {
        pelement=element[j3];
        element[j3]=element[j3+1];
        element[j3+1]=pelement;
        }
     }
}


int main(int argc, char* argv[])
{
vnesi();
h=1;
for (i=1;i<=n; i++)
 {
 povtoruvanja(a[i]);
  h++;
 } 
sortstr();
for (i=1;i<=n; i++)
  element[i].printstr();

printstr();
int g;
cin>>g;

        return 0;
}

