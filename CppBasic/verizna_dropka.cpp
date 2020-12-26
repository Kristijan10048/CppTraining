#include<iostream.h>
#include<stdlib.h>
#include<conio.h>

float a1[20],a,b;
int n;
int soberi(int br,int pa,int pb);
int soberi(int br,int pa,int pb)
{
 int pl;
 pl=pa+(pb*br);
 return(pl);
}

int nzd(int pa,int pb);
int nzd(int pa,int pb)
{
int i;
if(pa>pb)
  i=pa;
   else
    i=pb;
while(pa%i!=0||pb%i!=0)
 i--;
return(i);
}
int main(int argc, char* argv[])
{
int i,pom;
cout<<"N=";
cin>>n;
for(i=0;i<=n-1;i++)
 {
  cout<<"A["<<i<<"]=";
  cin>>a1[i];
  cout<<endl;
 }
n-=1;
a=1;
b=a1[n];
for(i=n;i>=1;i--)
{
a=soberi(a1[i-1],a,b);
pom=a;
a=b;
b=pom;
}
a=a/nzd(a,b);
b=b/nzd(a,b);
cout<<a<<"/"<<b;
system("pause");
        return 0;
}
//---------------------------------------------------------------------------
