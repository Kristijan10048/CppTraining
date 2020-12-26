#include <iostream>
#include <stdlib.h>
using namespace std;
enum note { middleC, Csharp, Eflat }; // Etc.

class Instrument {
protected:
int br;
public:
virtual void play(note) const {
    cout << "Instrument::play" <<br<<endl;
    }
virtual void inp()
{
 cout<<"Vnesei nekoj broj";
 cin>>br;
}

};

// Wind objects are Instruments
// because they have the same interface:
class Wind : public Instrument {
public:
  // Redefine interface function:
  void play(note) const {
    cout << "Wind::play"<<br<<endl;

  }
};

void tune(Instrument& i) {
  // ...
  i.play(middleC);
}

int main() {
  Instrument inst;
  Wind flute;
  cout<<"instrument"<<endl;
  inst.inp();
  tune(inst);
  cout<<"wind"<<endl;
  tune(flute); // Upcasting
  system("pause");
} ///:~
