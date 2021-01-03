#include <iostream.h>
#include<stdlib.h>
void f(int *p1,int d);
void f(int *p1,int d)
{
cout<<"____________"<<endl;
 for(int i=0;i<=d-1;i++)
  *(p1+i)=random(2);
}
int main ()
{

  int numbers[50],n,i;
  int * p;
  p=numbers;
  cout<<"Dolzina na nizata:";
  cin>>n;
  for (i=0;i<=n-1;i++)
   {
    cout <<"*(p+"<<i<<")=";
    cin>>*(p+i);
    cout<<endl;
   }
for (i=0;i<=n-1;i++)
{
 cout <<"*(p+"<<i<<")="<<*(p+i)<<" ,";
}
cout<<"F_____"<<endl;
f(p,n);
for (i=0;i<=n-1;i++)
   {
    cout <<"*(p+"<<i<<")="<<*(p+i)<<" ,";
    }
system("pause");
  return 0;
}

