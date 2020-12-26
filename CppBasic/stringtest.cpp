//---------------------------------------------------------------------------

#pragma hdrstop
# include <iostream.h>
# include <string.h>
# include <conio.h>
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
string s,s1="123";
char zn;
cout<<"vnesi string"<<endl;
cin>>s;
cout<<s<<","<<s1;
cout<<"Vnesi znak"<<endl;
cin>>zn;
s.insert(1,1,zn);
cout<<s;
s.clear();

getch();
        return 0;
}
//---------------------------------------------------------------------------
 