# include <iostream>
# include <conio.h>

using namespace std;

int ProzvodNaProstiMnoziteli(int argc, char* argv[])
{
	int n;
	cout << "Vnesete nekoj broj:";
	cin >> n;
	cout << "brojot " << n << "moze da se zapise kako proizvod na slednive prosti broevi:" << endl;
	int i = 2;
	while( n >= i )
	{
		while( n % i == 0 )
		{
			n = n / i;
			cout << i << ",";
		}
		i += 1;
	}
	_getch();
	return 0;
}