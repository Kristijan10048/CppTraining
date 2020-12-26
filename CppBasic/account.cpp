#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>


class Cash
{
private:
	int pin, money;
	string name, lname;
public:
	void CreatAaccount();
	void PrintAccount();
	void WithdrawCash();
	void AddCash();


	cash()
	{
		name = "";
		lname = "";
		pin = 0;
		money = 0;
	}


	cash(string n, string ln, int m = 0, int p = 0)
	{
		name = n;
		lname = ln;
		pin = p;
		money = m;
	}

};

void Cash::CreateAccount()
{
	cout << "Name:";
	cin >> name;
	cout << endl << "Last Name:";
	cin >> lname;
	cout << "Pin:";
	cin >> pin;
}

void Cash::PrintAccount()
{
	cout << "Name:" << name;
	cout << endl << "Last Name:" << lname;
	cout << "Pin:" << pin;
	cout << "Money:" << money << "$";
}


void cash::dodadi()
{
	int c, pp;
	cout << "Enter pin:";
	cin >> pin;
	if (pin == pp)
	{
		cout << "Cash deposit:";
		cin >> c;
		money += c;
		system("pause");
	}
	else
	{
		cout << "Wrong pin!!!" << endl << "Try agen" << endl;
		system("pause");
	}
}
void cash::izvadi()
{
	int c, pp;
	cout << "Enter pin:";
	cin >> pin;
	if (pin == pp)
	{
		cout << "Cash to withraw:";
		cin >> c;
		money -= c;
		system("pause");
	}
	else
	{
		cout << "Wrong pin!!!" << endl << "Try agen" << endl;
		system("pause");
	}
}
/*----------------------------CASH---End-----------------*/


/*----------------MAN------------------*/
class Man
{
protected:
	cash ch;
	string name, lname, addres;
public:
	virtual void enterdata();
	virtual void printdata();
};

void Man::EnterData()
{
	cout << "Name:";
	cin >> name;
	cout << endl << "Last name:";
	cin >> lname;
	cout << endl << "Adress:";
	cin >> addres;
	ch.createaccount();
}

void Man::PrintData()
{
	cout << "Name:" << name;
	cout << endl << "Last name:" << lname;
	cout << endl << "Adress:" << addres;
	ch.printaccount();
}
/*---------------------MAN__END-----------*/


/*--------------------worker-----------*/
class worker :man
{
	int paycheck;
	string wpl;
public:
	void enterdata();
	void printdata();
};

void worker::enterdata()
{
	cout << "Name:";
	cin >> name;
	cout << endl << "Last name:";
	cin >> lname;
	cout << endl << "Adress:";
	cin >> addres;
	cout << endl << "Work place:";
	cin >> wpl;
	cout << endl << "Paycheck:";
	cin >> paycheck;
	ch.createaccount();
}

void worker::printdata()
{
	cout << "Name:" << name;
	cout << endl << "Last name:" << lname;
	cout << endl << "Adress:" << addres;
	cout << endl << "Work place:" << wpl;
	cout << endl << "Paycheck:" << paycheck;
	ch.printaccount();
}
/*--------------WORKER--END----------------*/

worker wl[100];
man ml[100];


void addman(int&dol);
void addman(int&dol)
{
	wl[dol].enterdata();
	dol++;
}

void printman(int dol);
void printman(int dol)
{
	for (int i = 0; i <= dol; i++)
	{
		wl[i].printdata();
		cout << endl << "------------------" << endl;
	}
	system("pause");
}


int main(int argc, char* argv[])
{
	int mdol = 0, wdol = 0;
	char zn;
	do
	{
		clrscr();
		cout << "1.Add man" << endl
			<< "2.Add worker" << endl
			<< "3.Print man list" << endl
			<< "4.Print workers list" << endl
			<< "0.Exit";
		zn = getch();
		switch (zn)
		{
		case '1':
		{
			addman(mdol);
			break;
		}
		case '2':
		{
			break;
		}
		case '3':
		{
			printman(mdol);
			break;
		}
		case '4':
		{
			break;
		}
		}

	} while (zn != '0');
	return 0;
}
//---------------------------------------------------------------------------
