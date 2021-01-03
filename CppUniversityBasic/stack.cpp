#pragma hdrstop
#pragma argsused
# include <iostream.h>
# include <conio.h>
# include <string.h>
# include <dos.h>

class stack
{
 
 private:
  string st;
  void pushle(string &str)
  {
   int i,pom,leng;
   leng=str.length();
   for (i=leng-1;i>=0;i--)
    {str[i+1]=str[i];}
     str.resize(leng+1);
  }
 public:

 void put()
  {
   char zn,h;
   st=" ";
   do
    {
     if (st.length()!=10)
       {
        cout<<"vnesete edna bukva koja sto sakate da ja smestite ko stekot:";
        cin>>zn;
        pushle(st);
        st[0]=zn;
        cout<<endl<<"stekot po vnesuvaneto na bukvata izgleda vaka:"<<st<<endl;
       }
      else
        {
         cout<<"Stekot e poln!!"<<endl;
         cout<<st;
        }
     cout<<"Dali sakate uste da vnesuvate D/N";
     h=getch();
     h=toupper(h);
    }
  while(h=='D');
 }

}stacki;
int main(int argc, char* argv[])
{
 stacki.put();
        return 0;
}

