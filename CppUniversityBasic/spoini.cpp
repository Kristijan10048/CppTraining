#include<iostream.h>
#include<stdlib.h>
#include<conio.h>

void printni(int ap[110],int dol);
void printni(int ap[110],int dol)
{
  for(int i=0;i<=dol-1;i++)
  cout<<ap[i]<<"' ";
}

void vnesi(int *pn,int &dol);
void vnesi(int *pn,int &dol)
{
 cout<<"Kolku elementi ima nizata?";
 cin>>dol;
 for(int i=0;i<=dol-1;i++)
  {
   cout<<"Niza["<<i<<"]=";
   cin>>*(pn+i);
  }
system("pause");
}

void sortni(int *ni,int dol,int p)
{
 int pom;
 for(int i=0;i<=dol-2;i++)
  if(*(ni+i)>*(ni+i+1))
   {
    pom=*(ni+i);
    *(ni+i)=*(ni+i+1);
    *(ni+i+1)=pom;
   }
if(p!=2)
 sortni(ni,dol,p+1);
}


void pomestini(int *ni,int pos,int &dol);
void pomestini(int *ni,int pos,int &dol)
{
 if(dol==0) return;
 for(int i=pos;i<=dol-2;i++)
  *(ni+i)=*(ni+i+1);
 dol=dol-1;
}

void reductni(int *ni,int dol);
void reductni(int *ni,int dol)
{
 int i,j;
 for(i=0;i<=dol-1;i++)
  for(j=i+1;j<=dol-1;j++)
   if(*(ni+i)==*(ni+j))
    pomestini(ni,j,dol);
}


int minni(int *arr1,int &dolz1,int *arr2,int &dolz2,int &pdol);
int minni(int *arr1,int &dolz1,int *arr2,int &dolz2,int &pdol)
{
int min1,min2,i;
if(dolz1!=0)
 {
  min1=*(arr1+0);
  for(i=1;i<=dolz1-1;i++)
  {
   if(*(arr1+i)<min1)
    min1=*(arr1+i);
  }
 }
if(dolz2!=0)
 {
  min2=*(arr2+0);
   for(i=1;i<=dolz2-1;i++)
    if(min2>*(arr2+i))
     min2=*(arr2+i);
  }
if(min1<min2)
 {
 pomestini(arr1,0,dolz1);
 return(min1);
 }
 else
  {
   if(min2<min1)
    {
     pomestini(arr2,0,dolz2);
     return(min2);
    }
    else
    {
     pomestini(arr1,0,dolz1);
     pomestini(arr2,0,dolz2);
     pdol=pdol-1;
     return(min1);
    }
  }
}


void spoini(int *ni1,int dol1,int *ni2,int &dol2,int &vkdol,int *pni);
void spoini(int *ni1,int dol1,int *ni2,int &dol2,int &vkdol,int *pni)
{
int temp[100],vk;
sortni(ni1,dol1,1);
sortni(ni2,dol2,1);
reductni(ni1,dol1);
reductni(ni2,dol2);
vkdol=dol1+dol2;
vk=vkdol;
int i=0;
 for(i=0;i<=vk-1;i++)
  {
   temp[i]=minni(ni1,dol1,ni2,dol2,vkdol);
   cout<<"tempI:"<<temp[i]<<endl;
  }
pni=temp;
cout<<"\nTemp:";
for(i=0;i<=vkdol-1;i++)
 cout<<temp[i]<<", ";
system("pause");
}


int* spoinidemo(int *ni1,int dol1,int *ni2,int dol2);
int* spoinidemo(int *ni1,int dol1,int *ni2,int dol2)
{
int *pom;
pom=ni1;
for(int i=0;i<=dol2-1;i++)
 {
  *(pom+i+dol1)=*(ni2+i);
 }
return(pom);
}

int main(int argc, char* argv[])
{
int a[100],b[100],*c,na,nb,nc,c1[100];
vnesi(a,na);
clrscr();
cout<<"Ja vnesovte nizata:";
printni(a,na);
vnesi(b,nb);
system("pasue");
clrscr();
cout<<"Ja vnesovte nizata:";
printni(b,nb);
system("pause");
clrscr();
nc=na+nb;
cout<<endl;
spoini(a,na,b,nb,nc,c1);
printni(c1,nc);
system("pause");
        return 0;
}
//---------------------------------------------------------------------------
