#pragma hdrstop
#pragma argsused
# include <iostream.h>
# include <conio.h>
int main(int argc, char* argv[])
{
int n;
cout<<"Vnesete nekoj broj:";
cin>>n;
cout<<"brojot "<<n<<"moze da se zapise kako proizvod na slednive prosti broevi:"<<endl;
int i=2;
while (n>=i)
{
 while (n%i==0)
   {
   n=n/i;
   cout<<i<<",";
  }
 i+=1;
}
getch();
        return 0;
}

