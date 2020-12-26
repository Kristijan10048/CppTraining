#pragma hdrstop
#pragma argsused
# include <iostream.h>
# include <conio.h>
# include <string.h>
# include <dos.h>

class personaldat
{
 private:
  char pdat[200];
 public:
  void inppdata()
   {
    cout<<"Vnesete gi licnite podatoci:"<<endl;
    cin.getline(pdat,200);
    cout<<"Gi vnesovte podatocite:"<<endl;
    cout<<pdat;
   }
  void printpdata()
   {
    cout<<"Licni podatoci:"<<endl;
    cout<<pdat;
   }
};

class student
{
  private:
  string ime,prezime;
  float index,ocmat,ocfiz,ochem;
  public:
  personaldat rec;
  void vnesipod()
   {
    clrscr();
    cout<<"Vnesete go imeto na studentot:";
    cin>>ime;
    cout<<"Vnesete go prezimeto na studentot:";
    cin>>prezime;
    cout<<"Vnesete go indeksot na studentot:";
    cin>>index;
   }
  void vnesioceni()
   {
    char zn;
   do
    {
     clrscr();
     cout<<"Izberete opcija"<<endl;
     cout<<"1.Vnesuvanje na ocena po matematika"<<endl;
     cout<<"2.Vnesuvanje na ocena po fizika"<<endl;
     cout<<"3.Vnesuvanje na ocena po hemija"<<endl;
     cout<<"4.Vnesuvanje na oceni po site predmeti"<<endl;
     cout<<"0.Izlez"<<endl;
     zn=getch();
      switch (zn)
       {
        case '1':
            {
             clrscr();
             cout<<"Vnesete ja ocenata po matematika:";
             cin>>ocmat;
            }
         case '2':
            {
             clrscr();
             cout<<"Vnesete ja ocenata po fizika:";
             cin>>ocfiz;
            }
         case '3':
            {
             clrscr();
             cout<<"Vneset ja ocenata po hemija:";
             cin>>ochem;
            }
         case '4':
           {
             clrscr();
             cout<<"Vnesete ja ocenata po matematika:";
             cin>>ocmat;
             cout<<"Vnesete ja ocenata po fizika:";
             cin>>ocfiz;
             cout<<"Vneset ja ocenata po hemija:" ;
             cin>>ochem;
           }
       }
    }
    while(zn!='0');
   }
  void showdata()
  {
   cout<<"Ime:"<<ime<<endl;
   cout<<"Pezime:"<<prezime<<endl;
   cout<<"Matematika:"<<ocmat<<endl;
   cout<<"Fizika:"<<ocfiz<<endl;
   cout<<"Hemija:"<<ochem<<endl;
  }
 void prosek()
  {
   cout<<"Prosekot na studentot e:"<<(ocmat+ochem+ocfiz)/3;
  }


}obj;

int main(int argc, char* argv[])
{
obj.rec.inppdata();
obj.vnesipod();
obj.vnesioceni();
obj.showdata();
obj.prosek();
obj.rec.printpdata();
getch();
        return 0;
}

