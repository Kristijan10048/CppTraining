#ifdef NOT_FIXED
#pragma hdrstop
#pragma argsused
# include <iostream.h>
# include <dos.h>
# include <conio.h>

class dropka
{
private:
	int imenitel, broitel;
public:
	dropka operator+(dropka&);
	dropka operator-(dropka&);
	dropka operator*(dropka&);
	dropka operator/(dropka&);

	int vratiim()
	{
		return(imenitel);
	}
	int vratibro()
	{
		return(broitel);
	}
	void vnsiimenitel()
	{
		cout << "Imenitel:";
		cin >> imenitel;
	}
	void vnesibroitel()
	{
		cout << "Broitel:";
		cin >> broitel;
	}
	void printdropka()
	{
		cout << broitel << "/" << imenitel;
	}
	float realenbroj()
	{
		float im, br;
		im = imenitel;
		br = broitel;
		return(br / im);
	}
	dropka mnozi(dropka dr)
	{
		dropka tempdr;
		tempdr.imenitel = imenitel * dr.imenitel;
		tempdr.broitel = broitel * dr.broitel;
		return(tempdr);
	}
	void skrati()
	{
		int br, i = 2;
		if( imenitel > broitel )
		{
			br = imenitel;
		}
		else
		{
			br = broitel;
		}
		while( br != i )
		{
			while( imenitel % i == 0 && broitel % i == 0 )
			{
				imenitel = imenitel / i;
				broitel = broitel / i;
			}
			i++;
		}
	}

	dropka podeli(dropka dr)
	{
		dropka tempdr;
		tempdr.imenitel = imenitel * dr.broitel;
		tempdr.broitel = broitel * dr.imenitel;
		return(tempdr);
	}
	dropka soberi(dropka dr)
	{
		dropka tempdr;
		tempdr.broitel = (broitel * dr.imenitel) + (imenitel * dr.broitel);
		tempdr.imenitel = imenitel * dr.imenitel;
		return(tempdr);
	}
	dropka()
	{
		imenitel = 0;
		broitel = 0;
	}
	dropka(int im, int br)
	{
		imenitel = im;
		broitel = br;
	}
	dropka odzemi(dropka dr)
	{
		dropka tempdr(1, 1);
		tempdr.broitel = broitel * dr.imenitel - imenitel * dr.broitel;
		tempdr.imenitel = imenitel * dr.imenitel;
		return(tempdr);
	}
	~dropka()
	{
		textcolor(RED);
		printf("Asta la vista baby\n");
	}

}drop1, drop2, drop3, drop4, drop5;


dropka dropka::operator+(dropka& obj)
{
	dropka tempdr;
	tempdr.broitel = broitel * obj.imenitel + imenitel * obj.broitel;
	tempdr.imenitel = imenitel * obj.imenitel;
	return tempdr;
}

dropka dropka::operator-(dropka& obj)
{
	dropka tempdr;
	tempdr.broitel = broitel * obj.imenitel - imenitel * obj.broitel;
	tempdr.imenitel = imenitel * obj.imenitel;
	return tempdr;
}

dropka dropka::operator*(dropka& obj)
{
	dropka tempdr;
	tempdr.broitel = broitel * obj.broitel;
	tempdr.imenitel = imenitel * obj.imenitel;
}

dropka dropka operator

int main(int argc, char* argv[])
{
	char zn;
	do
	{
		clrscr();
		cout << "Izberi opcija:" << endl;
		cout << "1.Operacii preku funkcii" << endl;
		cout << "2.Operacii preku operatori" << endl;
		cout << "0.Izlez" << endl;
		zn = getch();
		switch( zn )
		{
		case '1':
		{
			drop1.vnesibroitel();
			drop1.vnsiimenitel();
			cout << "Vnesete ja vtorata dropka" << endl;
			drop2.vnesibroitel();
			drop2.vnsiimenitel();
			drop3 = drop1.mnozi(drop2);
			drop3.printdropka();
			drop3.skrati();
			cout << endl;
			drop3.printdropka();
			cout << "podeli rezultat" << endl;
			drop4 = drop3.podeli(drop1);
			drop4.printdropka();
			cout << "sobiranje" << endl;
			drop5 = drop1.soberi(drop2);
			drop5.skrati();
			drop5.printdropka();
			cout << endl << "Odzemanje" << endl;
			drop3 = drop1.odzemi(drop2);
			drop3.printdropka();
			getch();
			break;
		}
		case '2':
		{
			drop1.vnesibroitel();
			drop1.vnsiimenitel();
			cout << "Vnesi ja vtorata dropka" << endl;
			drop2.vnesibroitel();
			drop2.vnsiimenitel();
			drop3 = drop1 + drop2;
			cout << "Sobrani dvete dropki" << endl;
			drop3.skrati();
			drop3.printdropka();
			drop3 = drop1 - drop2;
			cout << "Odzemeni drop1-drop2" << endl;
			drop3.skrati();
			drop3.printdropka();
			getch();
			break;
		}
		}
	}
	while( zn != '0' );
	return 0;
}
#endif