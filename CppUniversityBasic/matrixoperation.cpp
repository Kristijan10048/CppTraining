
#include<iostream>
#include<conio.h>
#include<fstream>
#ifdef NOT_FIXED
#include<stdlib.h>

using namespace std;

void ddesno();
void dlevo();
void inputdimensions();
void zamenaredsokol();
void printmatrix(int k, int r);
void matrixspin();


int matrix[10][10], kol, red;

void clrscr()
{
	std::system("cls");
}

void matrixspin()
{
	int i, j, n, k = 1, pk;
	cout << "Broj na previtkuvanja:";
	cin >> n;
	matrix[0][0] = 1;
	for( i = 1; i <= n - 1; i++ )
	{
		matrix[i][0] = matrix[i - 1][0] + k;
		k += 2;
	}
	for( i = 1; i <= n - 1; i++ )
		for( j = 1; j <= i; j++ )
		{
			matrix[i][j] = matrix[i][j - 1] + 1;
		}
	k = 3;
	for( i = 1; i <= n - 1; i++ )
	{
		matrix[0][i] = matrix[0][i - 1] + k;
		k += 2;
	}
	k = 5;
	pk = 5;
	for( i = 1; i <= n - 1; i++ )
	{
		k = pk;
		for( j = i + 1; j <= n - 1; j++ )
		{
			matrix[i][j] = matrix[i][j - 1] + k;
			k += 2;
		}
		pk += 2;
	}
	printmatrix(n - 1, n - 1);
}

void printmatrix(int k, int r)
{
	int i, j;
	for( i = 0; i <= k; i++ )
	{
		for( j = 0; j <= r; j++ )
			cout << matrix[i][j] << "-";
		cout << endl;
	}
	system("pause");
}

void inputdimensions()
{
	clrscr();
	cout << "Koloni:";
	cin >> kol;
	cout << endl << "Redici:";
	cin >> red;
}
void ddesno()
{
	int i, j;
	inputdimensions();
	for( i = 0; i <= kol - 1; i++ )
	{
		for( j = i; j <= red - 1; j++ )
		{
			cout << i << j << "-";
		}
		cout << endl;
	}
	system("pause");
}

void dlevo()
{
	inputdimensions();
	int i, j;
	for( i = 0; i <= red - 1; i++ )
	{
		for( j = 0; j <= i; j++ )
		{
			cout << i << j << "-";
		}
		cout << endl;
	}
	system("pause");
}

void zamenaredsokol()
{
	clrscr();
	int n, i, j, p, q, pom;;
	cout << "Dimenzija na kvadratnata matrica:";
	cin >> n;
	cout << "Vnesete gi elementite na matricata:" << endl;
	for( i = 0; i <= n - 1; i++ )
		for( j = 0; j <= n - 1; j++ )
		{
			cout << "M[" << i << "]" << "[" << j << "]=";
			cin >> matrix[i][j];
		}
	cout << "ja vnesovte matricata:" << endl;
	printmatrix(n - 1, n - 1);
	cout << "koja redica sakate da ja zamenete so koja kolona";
	cin >> p >> q;
	p = p - 1;
	q -= 1;
	for( i = 0; i <= n - 1; i++ )
	{
		pom = matrix[p][i];
		matrix[p][i] = matrix[i][q];
		matrix[i][q] = pom;
	}
	printmatrix(n - 1, n - 1);
}

int main(int argc, char* argv[])
{
	char zn;
	do
	{
		clrscr();
		cout << "1.Desen triagolnik" << endl;
		cout << "2.Lev triagolnik" << endl;
		cout << "3.Zamna na redica so kolona" << endl;
		cout << "4.Spirala vo matrica" << endl;
		cout << "5.Transponirana matrica" << endl;
		cout << "0.Izlez" << endl;
		zn = getch();
		switch( zn )
		{
		case '1':
		{
			ddesno();
		}
		case '2':
		{
			dlevo();
		}
		case '3':
		{
			zamenaredsokol();
		}
		case '4':
		{
			matrixspin();
		}
		}
	}
	while( zn != '0' );
	system("pause");

	return 0;
}
#endif