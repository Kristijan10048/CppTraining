#pragma hdrstop
#pragma argsused
# include <iostream.h>
# include <conio.h>
# include <dos.h>
void timer1();
void calctime();
struct  time t;

void calctime()
{
int sek;
int h,m,s;
cout<<"vnesi go vremeto vo sekundi";
cin>>sek;
h=sek/3600;
sek=sek%3600;
m=sek/60;
s=sek%60;
cout<<"H:"<<h<<" M:"<<m<<" S:"<<s;
getch();
}

void timer1()
{
 gettime(&t);
 cprintf("The current time is: %2d:%02d:%02d.%02d\n\r",
 t.ti_hour,t.ti_min,t.ti_sec,t.ti_hund);
 getch();
}

int main(int argc, char* argv[])
{
char zn;
do
 {
  clrscr();
  cout<<"Izberi opcija"<<endl<<"1.Timer"<<endl<<"2.CalculateTime"<<endl;
  cin>>zn;
   switch(zn)
    {
     case '1':timer1();
      break;
     case '2':calctime();
      break;
     default :cout<<"Muuu";
    }
  }
while (zn!='0');
        return 0;
}


