#ifdef NOT_FIXED
#include <iostream>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
bool proveriint(int br, int pp, int pq)
{
	int i;
	bool pb = false;
	for( i = pp; i <= pq; i++ )
	{
		if( br == i )
			pb = true;
	}
	return(pb);
}

bool vointerval(int n[20], int dol, int pp, int pq);
bool vointerval(int n[20], int dol, int pp, int pq)
{
	int i = 0, j = 0;
	while( i <= dol )
	{
		if( proveriint(n[i], pp, pq) == true )
			j++;
		i++;
	}
	if( j == pq - pp + 1 )
		return(true);
	else
		return(false);
}

void printa(int p[20], int size)
{
	cout << "\nPodniza:";
	for( int i = 0; i <= size; i++ )
		cout << p[i] << ", ";
	cout << "\n";
}

int main(int argc, char* argv[])
{
	int n, a[20], i, j, p, q, tempa[20];
	char zn;

	cout << "1.Vnesuvanje na niza preku tastatura\n"
		<< "2.Gotova niza";
	zn = getch();
	switch( zn )
	{
	case '1':
	{
		cout << "N=";
		cin >> n;
		for( i = 0; i <= n - 1; i++ )
		{
			cout << "A[" << i << "]=";
			cin >> a[i];
			cout << "\r";
		}
	}
	case '2':
	{
		a[0] = 1; a[1] = 2; a[2] = 3; a[3] = 2;
		a[4] = 1;
		n = 5;
	}
	}
	clrscr();
	cout << "Leva granica:";
	cin >> p;
	cout << "Desna granica:";
	cin >> q;
	int raz = q - p, k;
	for( i = 0; i <= n - raz - 1; i++ )
	{
		k = 0;
		for( j = i; j <= i + raz; j++ )
		{
			tempa[k] = a[j];
			k++;
		}
		if( vointerval(tempa, q - p, p, q) == true )
			printa(tempa, q - p);
		cout << "\n";
	}
	system("pause");
	return 0;
}
//---------------------------------------------------------------------------
#endif