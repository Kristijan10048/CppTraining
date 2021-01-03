using namespace std;

#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

class Account
{
private:
	int  m_iPin, m_iBalance;
	string m_sFirstName, m_sLastName;
public:
	void PromtCreateAccount();
	void PrintAccount();
	void AddCashAmount();
	void WithdrawCashAmount();
	bool CheckPin(int iPin);

	//default constructor
	Account()
	{
		m_sFirstName = "";
		m_sLastName = "";
		m_iBalance = 0;
		m_iPin = 0;
	}

	Account(string sFirstName, string sLastName, int iCurrentBalance, int iPin)
	{
		m_sFirstName = sFirstName;
		m_sLastName = sLastName;
		m_iBalance = iCurrentBalance;
		m_iPin = iPin;
	}
};

void Account::PromtCreateAccount()
{
	cout << "Name:";
	cin >> m_sFirstName;
	cout << endl << "Last Name:";
	cin >> m_sLastName;
	cout << "Pin:";
	cin >> m_iPin;
}

void Account::PrintAccount()
{
	cout << "First Name:" << m_sFirstName << endl;
	cout << "Last Name:" << m_sLastName << endl;
	cout << "Pin:" << m_iPin << endl;
	cout << "Current balance:" << m_iBalance << "$" << endl;
}

void Account::AddCashAmount()
{
	int iCurrAmount, iCurrPin;
	cout << "Enter your pin:";
	cin >> iCurrPin;
	if (CheckPin(iCurrPin))
	{
		cout << "Amount to add:";
		cin >> iCurrAmount;
		m_iBalance += iCurrAmount;
		system("pause");
	}
	else
	{
		cout << "Wrong pin!" << endl << "Try agen" << endl;
		system("pause");
	}
}

void Account::WithdrawCashAmount()
{
	int iCurrAmmount, iCurrPin;
	cout << "Enter pin:";
	cin >> iCurrPin;
	if (CheckPin(iCurrPin))
	{
		cout << "Ammount to withraw:";
		cin >> iCurrAmmount;
		m_iBalance -= iCurrAmmount;
		system("pause");
	}
	else
	{
		cout << "Wrong pin!!!" << endl << "Try agen" << endl;
		system("pause");
	}
}

bool Account::CheckPin(int iPin)
{
	return m_iPin == iPin;
}

class Person
{
protected:
	Account m_oAccount;
	string m_sFirstName, m_sLastName, m_sAddres;
public:
	virtual void EnterPersonalData();
	virtual void PrinPersonaltData();
};

void Person::EnterPersonalData()
{
	cout << "First Name:";
	cin >> m_sFirstName;
	cout << endl << "Last name:";
	cin >> m_sLastName;
	cout << endl << "Adress:";
	cin >> m_sAddres;

	//m_oAccount.PromtCreateAccount();
}

void Person::PrinPersonaltData()
{
	cout << "First Name:" << m_sFirstName << endl;
	cout << "Last name:" << m_sLastName << endl;
	cout << "Adress:" << m_sAddres << endl;

	//ch.printaccount();
}

class Employee : Person
{
	int m_iPayCheck;
	string wpl;
public:
	void EnterPersonalData();
	void PrintPersonalData();
};

void Employee::EnterPersonalData()
{
	cout << "Name:";
	cin >> m_sFirstName;
	cout << endl << "Last name:";
	cin >> m_sLastName;
	cout << endl << "Adress:";
	cin >> m_sAddres;
	cout << endl << "Work place:";

	//cin >> wpl;
	//cout << endl << "Paycheck:";


	//cin >> paycheck;
	//ch.createaccount();
}

void Employee::PrintPersonalData()
{
	cout << "First Name:" << m_sFirstName;
	cout << endl << "Last name:" << m_sLastName;
	cout << endl << "Adress:" << m_sAddres;
	//cout << endl << "Work place:" << wpl;
	//cout << endl << "Paycheck:" << paycheck;
	//ch.printaccount();
}

Employee wl[100];
Person ml[100];

void AddPerson(int& dol);
void PrintPerson(int dol);
void clrscr();

void clrscr()
{
	std::system("cls");
}


void AddPerson(int& dol)
{
	wl[dol].EnterPersonalData();
	dol++;
}


void PrintPerson(int dol)
{
	for (int i = 0; i <= dol; i++)
	{
		wl[i].PrintPersonalData();
		cout << endl << "------------------" << endl;
	}
	system("pause");
}


int main(int argc, char* argv[])
{
	int mdol = 0, wdol = 0;
	char key;
	do
	{
		clrscr();
		cout << "1.Add Person" << endl
			<< "2.Add Employee" << endl
			<< "3.Print list of employees" << endl
			<< "4.Print workers list" << endl
			<< "0.Exit";
		key = getch();
		
		switch (key)
		{
			case '1':
			{
				AddPerson(mdol);
				break;
			}
			case '2':
			{
				break;
			}
			case '3':
			{
				PrintPerson(mdol);
				break;
			}
			case '4':
			{
				break;
			}
		}

	} while (key != '0');
	return 0;
}