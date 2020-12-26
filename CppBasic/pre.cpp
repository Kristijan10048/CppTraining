#pragma hdrstop
# include <iostream.h>
# include <conio.h>
# include <iomanip.h>
#pragma argsused
int faktoriel(int br);
int faktoriel(int br)
{
int fak=1;
for (int j=1;j<=br;j++)
 fak=fak*j;
return(fak);
}
int main(int argc, char* argv[])
{
int toc,i;
cout<<"So kolkava tocnost sakate da go presmetate brojot E?";
cin>>toc;
double preth ,bre,t=1,fk;
for (i=1; i<=toc; i++)
   t=t/10;
bre=2;
i=2;
do
 {
  preth=bre;
  fk=faktoriel(i);
  bre=bre+ 1/fk;
  i++;
 }
while(bre-preth>t);

cout<<setprecision(100)<<bre;
getch();
        return 0;
}

 