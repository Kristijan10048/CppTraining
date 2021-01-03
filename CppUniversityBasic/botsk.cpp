#include <vcl.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream.h>

double stepen(float br,int exp);
double stepen(float br,int exp)
{
 float st=1;
 for(int i=1;i<=exp;i++)
  st=st*br;
return(st);
}

int main(int argc, char* argv[])
{
int i=1;;
float h,ho,x=0,minotsk=0,dol;
cout.setf(ios_base::fixed);
cout<<"Od kolkava visina e pustena topkata?";
cin>>h;
cout<<endl<<"Kolkava e visinata na prviot otskok?";
cin>>ho;
cout<<endl<<"Do koja visina da se presmetuva rastojanieto?";
cin>>minotsk;
dol=h;
x=ho;
cout.precision(50);
while(x>minotsk)
{
 x=stepen(ho,2)/h;
 dol=dol+ho+x;
 cout<<"dol="<<x<<endl;
 h=ho;
 ho=x;
 i++;
}
;
cout<<"Vkupna dolzina="<<dol<<"broj na otskoknuvanja="<<i-1;
system("pause");
        return 0;
}
//---------------------------------------------------------------------------

