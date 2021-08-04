#ifdef NOT_FIXED

# include <iostream>
# include <conio.h>
# include <dos.h>
# include <string.h>
class vraboten
{
private:
	string ime, prezime;
	unsigned int godnavrab;
public:
	void inpbasicdata()
	{
		cout << "Ime:";
		cin >> ime;
		cout << endl << "Prezime:";
		cin >> prezime;
		cout << endl << "Godina na vrabotuvanje:";
		cin >> godnavrab;
	}
	void printbasicdata()
	{
		cout << "Ime:" << ime << endl;
		cout << "Prezime:" << prezime << endl;
		cout << "Godina na vrabotuvaneje:" << godnavrab;
	}
	vraboten()
	{
		cout << "Start vraboten" << endl;
	}
	~vraboten()
	{
		cout << "Bye vraboten" << endl;
	}
}test;


class profesor :vraboten
{
private:
	string zanimanje, oblast;
	unsigned int brpred;
public:
	void inpprofdata()
	{
		inpbasicdata();
		cout << "Zanimanje:";
		cin >> zanimanje;
		cout << endl << "Oblast:";
		cin >> oblast;
	}
	void printprofdata()
	{
		printbasicdata();
		cout << "Zanimanje:" << zanimanje << endl;
		cout << "Oblast:" << oblast << endl;
	}
	profesor()
	{
		cout << "Start profesor" << endl;
	}
	~profesor()
	{
		cout << "Bye profesor" << endl;
	}
};
class asistent :vraboten
{
private:
	string zanimanje, mentor;
	unsigned int brnapred;
public:
	void inpasistentdat()
	{
		inpbasicdata();
		cout << "Zanimanje:";
		cin >> zanimanje;
		cout << endl << "Mentor:";
		cin >> mentor;
		cout << "Broj na casovi:";
		cin >> brnapred;
	}
	void printasistentdata()
	{
		printbasicdata();
		cout << "Zanimanje:" << zanimanje << endl;
		cout << "Mentor:" << mentor << endl;
		cout << "Broj na casovi:" << brnapred;
	}
	asistent()
	{
		cout << "asshole start" << endl;
	}
	~asistent()
	{
		cout << "asshol terminated" << endl;
	}


};

class demonstrator :vraboten
{
private:
	unsigned int rabvreme;
public:
	void inpdemonstratordata()
	{
		inpbasicdata();
		cout << "Rabotno vreme:";
		cin >> rabvreme;
	}
	void printdemostratordata()
	{
		printbasicdata();
		cout << "Rabotno vreme:" << rabvreme;
	}
	demonstrator()
	{
		cout << "Demonstrator start" << endl;
	}
	~demonstrator()
	{
		cout << "Demonstrator bye:" << endl;
	}
};

profesor jovance;
asistent ljupco;
demonstrator klapco;
int main(int argc, char* argv[])
{
	test.inpbasicdata();
	test.printbasicdata();
	cout << "Vnesi podatoci za jovance:" << endl;
	jovance.inpprofdata();
	jovance.printprofdata();
	cout << "Vnese te gi podatocite za naduenko:" << endl;
	ljupco.inpasistentdat();
	ljupco.printasistentdata();
	cout << "Vnesi gi podatocite za kalpco" << endl;
	klapco.inpdemonstratordata();
	klapco.printdemostratordata();
	getch();
	return 0;
}
#endif