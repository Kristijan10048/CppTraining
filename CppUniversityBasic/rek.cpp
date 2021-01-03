#include <iostream.h>
#include <stdlib.h>
int br;
int najgolem(int *p1,int dol);
int najgolem(int *p1,int dol)
{
 if(dol==0)
  return(br);
   else
    {
     if( br<*(p1+dol))
      br=*(p1+dol);
      najgolem(p1,dol-1);
    }
}

int main(int argc, char* argv[])
{
int n,a[100],*p;
cout<<"N=";
cin>>n;
for(int i=0;i<=n-1;i++)
 {
  a[i]=random(100);
  cout<<a[i]<<", ";
 }
p=a;
cout<<"Najgolem e:"<<najgolem(p,n-1)<<endl;
system("pause");
        return 0;
}
//---------------------------------------------------------------------------
