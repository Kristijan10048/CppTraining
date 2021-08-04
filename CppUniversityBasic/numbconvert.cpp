#ifdef NOT_FIXED
# include <iostream>
# include <conio.h>

using namespace std;

void dekvobin(int br);
void vndek();
void vnbin();
void vnokt();
void binvodek();
void meni(char r);
int pbits[30], bits[30], numb, bindolz;

void dekvobin(int br)
{
	int k = 0;
	int i1;
	while( br != 0 )
	{
		pbits[k] = br % 2;
		br = br / 2;
		k = k + 1;
	}
	int z = 0;
	for( i1 = k - 1; i1 >= 0; i1-- )
	{
		bits[z] = pbits[i1];
		z = z + 1;
	}
	cout << "Brojot" << numb << "pretovoren vo binaren:";
	for( i1 = 0; i1 <= z - 1; i1++ )
		cout << bits[i1];
	getch();
}

void binvodek()
{
	int b, dekbr = 0;
	dekbr = 2 * pbits[0] + pbits[1];
	for( int i1 = 2; i1 <= bindolz - 1; i1++ )
		dekbr = dekbr * 2 + pbits[i1];
	cout << "Go dobivte brojot:" << dekbr;
	getch();
}

void vndek()
{
	cout << "Vnesete go brojot sto sakate da go pretvorite:";
	cin >> numb;
	meni('1');
}

void vnokt()
{
	cout << "Vnesete go brojot vo oktalen broen sistem";

}

void vnbin()
{
	int i1 = 0;
	char zn;
	cout << "Vnesete go binarniot broj sto sakate da go pretvorite" << endl;
	cout << "Pritisnete * za kraj na brojot" << endl;
	do
	{
		cin >> zn;
		if( zn == '1' | zn == '0' )
		{
			switch( zn )
			{
			case '0': pbits[i1] = 0;
				break;
			case '1':pbits[i1] = 1;
			}
		}
		i1 = i1 + 1;
	}
	while( zn != '*' );
	bindolz = i1 - 1;
	cout << "Go vnesovte brojot";
	for( int j1 = 0; j1 <= i1 - 2; j1++ )
		cout << pbits[j1];
	cout << endl;
	cout << "Pritisnete bilo koj taster za da prodolzite" << endl;
	getch();
	meni('2');
}

void meni(char r)
{
	char ch;
	do
	{
		clrscr();
		cout << "Izberete broen sistem vo koj sakate da go pretvorite brojot:" << endl;
		switch( r )
		{
		case '1':
		{
			cout << "1.Binaren" << endl;
			cout << "2.Oktalen" << endl;
			cout << "3.Heksaden" << endl;
			ch = getch();
			switch( ch )
			{
			case '1':
			{
				cout << "Brojot" << numb << "izbrevte da go pretvorite vo binaren" << endl;
				dekvobin(numb);
			}
			break;
			}
		}
		break;
		case '2':
		{
			cout << "1.Dekaden" << endl;
			cout << "2.Oktalen" << endl;
			cout << "3.Heksaden" << endl;
			ch = getch();
			switch( ch )
			{
			case '1':
			{
				cout << "Izbravte binaren sistem" << endl;
				binvodek();
			}
			}
		}
		break;
		case '0': break;
		}
	}
	while( ch != '0' );
}

int main1(int argc, char* argv[])
{
	char zn;
	do
	{
		clrscr();
		cout << "Izberete opcija:" << endl;
		cout << "1.Vnesuvanje na dekaden broj" << endl;
		cout << "2.Vnesuvanje na binaren broj" << endl;
		cout << "3.Vnesuvanje na oktalen broj" << endl;
		cout << "4.Vnesuvanje na heksaden broj" << endl;
		cout << "0.Izlez" << endl;
		zn = getch();
		switch( zn )
		{
		case '1':vndek();
			break;
		case '2':vnbin();
		}
	}
	while( zn != '0' );
	return 0;
}
#endif