#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

int& f()
{
 int i,ni[10];
 for(i=0;i<=5;i++)
  ni[i]=i;
return(ni);
}
int main(int argc, char* argv[])
{
int a,b,*p,i,mat[10];
cout<<"Vn";
cin>>a;
cout<<"Vn:";
cin>>b;
p=&a;
b=*p;
cout<<"b="<<b;
system("pause");
&mat=f();
for(i=0;i<=5;i++)
cout<<*(mat+i)<<"--";
system("pause");

        return 0;
}
//---------------------------------------------------------------------------
