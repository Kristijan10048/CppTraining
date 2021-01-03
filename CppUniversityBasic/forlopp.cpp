#pragma hdrstop
#include <iostream.h>
#include <string.h>
#include <conio.h>
#pragma argsused
void testfor1();
void testfor2();
void strtest ();
void prozor();
void boi();
int n,i,j;
int ni[20];
string st,ts;

void testfor1()
{
 clrscr();
 cout << "Vnesete n: ";
 cin >> n;
 for (i=0, j=n+5; i<=n && j>=0; ++i, j--)
 cout << i << " " << j << endl;
}

void testfor2()
{
 clrscr();
 cout<<"Vnesi n/n";
 cin>>n;
 int broj=0, zbir=0;
  for ( ; broj < n;broj+=2 )
   {
   zbir+=broj;
   cout<<"broj:"<<broj<<endl;
   cout<<zbir<<endl;
   }
}

void strtest ()
{
clrscr();
int dol;
ts='blas';
cout<<"Vnesi nikoj string:";
cin>>st;
dol=st.size();
 for (i=0; i<=dol-1; i++)
  {
   cout<<"st["<<i<<"]="<<st[i]<<endl;
  }
st=st+ts;
cprintf("spoen string");
cout<<st<<endl;
st.insert(st.length()/2,"--");
cout<<st<<endl;
for (i=0; i<=dol-1; i+=2)
 st[i]=upcase(st[i]);
cout<<st; 
getch();
}

void boi ()
{
clrscr();
int i1,j1;
clrscr();
   for (i1=0; i1<9; i1++)
   {
       for (j1=0; j1<80; j1++)
          cprintf("C");
       cprintf("\r\n");
       textcolor(i1+1);
       textbackground(i1);
   }

getch();
}

void prozor()
{
   window(10,10,40,11);
   textcolor(BLACK);
   textbackground(WHITE);
   cprintf("This is a test\r\n");
getch();
}
int main()
{
int g;
char zn;
do
{
 clrscr();
 textcolor(2);
 textbackground(0);
 window(10,10,40,20);
 cprintf("Izberi opcija:\n\r");
 cprintf("1.for1\r\n");
 cprintf("2.for2\n\r");
 cprintf("3.string\n\r");
 cprintf("0.exit\n\r");
 zn=getch();
 switch(zn)
  {
   case '1':testfor1();
    break;
   case '2':testfor2();
    break;
   case '3':strtest();
    break;
   case '4':boi();
   break ;
   case '5':prozor();
   default :cout<<"Muuu";
  }
}
while (zn!='0');
getch();

        return 0;
}

