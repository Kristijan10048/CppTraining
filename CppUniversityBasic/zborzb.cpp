#include <conio.h>
#include<stdlib.h>
#include<iostream.h>
#include<string.h>
#include<vcl.h>
string s;

bool palindrom(string st);
bool palindrom(string st)
{
 int i,dol;
 dol=st.length();
  for(i=0;i<=(dol-1)/2;i++)
   if(st[i]!=st[dol-1-i])
    return(false);
  return(true);
}

void substr();
void substr()
{
 int i,j,k,dol;
 dol=s.length();
 string pom;
 for(k=1;k<=dol-1;k++)
  for(i=0;i<=dol-1-k;i++)
   {
    pom.clear();
    for(j=i;j<=i+k;j++)
     {
      pom=pom+s[j];
      cout<<s[j];
     }
    if(palindrom(pom)==true)
      cout<<"---Podnizata go ima baraniot oblik"<<endl;
    cout<<endl;  
   }

}


int main(int argc, char* argv[])
{
cout<<"Text";
cin>>s;
substr();
system("pause");

        return 0;
}
//---------------------------------------------------------------------------
