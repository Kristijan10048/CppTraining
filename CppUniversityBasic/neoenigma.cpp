#ifdef NOT_FIXED
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#define uint unsigned int

using namespace std;

const kol = 30, red = 3;
uint matrix[kol][red], pomencode[500], dolz, z, pom[500], inputencrarr[500], dolzinp, indexdol;
uint matindex[50], dim;
char niza[1000];



char ni[28] = "qaegfmprbzcxl ivydnksjbhuot_";
void pomestides();
void genmat();
void printmat();
int retindex(char zna);
void inputchar();
void encodearr();
void savenecription();
void printencodearr();
void genrandomatrix();
void loadmatrix();
void resetni();
void findchar();
void pomestidesno();
void findindex();
void decriptmatrix();
void izbor1();
void izbor2();
void readencriptionfile();
void readfile();
void pomestides()  /*POMESTUVANJE NA NIZATA SO KARAKTERI*/
{
	char p;
	int i = 0;
	p = ni[25];
	for( i = 25; i >= 0; i-- )
	{
		ni[i] = ni[i - 1];
	}
	ni[0] = p;
}


void genmat()          /*GENERIRANJE NA REDOSLEDNA MATRICA*/
{
	int i, j, zprt = 100;
	for( i = 0; i <= kol - 1; i++ )
	{
		for( j = 0; j <= red - 1; j++ )
		{
			matrix[i][j] = zprt;
			zprt++;
		}
	}
}

void printmat()        /*PECATENJE NA MATRICATA*/
{
	int i, j;
	for( i = 0; i <= kol - 1; i++ )
	{
		for( j = 0; j <= red - 1; j++ )
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}


int retindex(char zna)
{
	int i = 0;
	while( zna != ni[i] )
	{
		i++;
	}
	return(i);
}

void readfile()
{
	ifstream f;
	char path[100], buf, ichar[100000];
	uint j = 0, i;
	cout << "Vnesete ja patekata na fajlot sto sakate da go procitate:" << endl;
	cin >> path;
	f.open(path);
	if( !f )
	{
		cout << "greska";
	}
	else
	{
		while( !f.eof() )
		{
			f >> buf;
			ichar[j] = buf;
			j++;
		}
	}
	cout << "Ja vcitavte datotekata:" << endl;
	cout << ichar;
	system("pause");
	dolz = j;
	for( i = 0; i <= j - 1; i++ )
	{
		pomencode[i] = retindex(ichar[i]);
		pomestides();
	}
}

void inputchar()
{
	int i = 0, j = 0;
	char zn, ichar[50];
	cout << "vn:";
	do
	{
		zn = getche();
		zn = tolower(zn);
		if( zn != '\r' )
		{
			ichar[j] = zn;
			j++;
		}
	}
	while( zn != '\r' );
	dolz = j;
	for( i = 0; i <= j - 1; i++ )
	{
		pomencode[i] = retindex(ichar[i]);
		pomestides();
	}
}

void encodearr()
{
	char zn;
	do
	{
		clrscr();
		cout << "1.Vnesuvanje na poraka preku tastatura" << endl;
		cout << "2.Vnesuvanje na datoteka za enkriptiranje" << endl;
		zn = getch();
		switch( zn )
		{
		case '1':
		{
			inputchar();
		}
		case '2':
		{
			readfile();
		}
		}
	}
	while( zn != '0' );
	int i, k;
	z = 0;
	for( k = 0; k <= dolz - 1; k++ )
	{
		for( i = 0; i <= 2; i++ )
		{
			pom[z] = matrix[pomencode[k]][i];
			z++;
		}
	}
}

void savenecription()
{
	char path[100];
	fstream f;
	int i;
	cout << "Vnesete ja patekata na fajlot:";
	cin >> path;
	f.open(path);
	if( !f )
	{
		cout << "Greska" << endl;
	}
	else
	{
		for( i = 0; i <= z - 1; i++ )
		{
			f << pom[i] << " ";
			if( i % 20 == 0 )
			{
				f << endl;
			}
		}
	}

}


void printencodearr()
{
	char ch;
	int i;
	cout << "------------------------------------------------------" << endl;
	for( i = 0; i <= z - 1; i++ )
	{
		cout << pom[i] << "--";
	}
	cout << endl << "Dali sakate da zacuvate?(D/N)";
	ch = getch();
	ch = toupper(ch);
	if( ch == 'D' )
	{
		savenecription();
	}
}


void genrandomatrix()
{
	char path[100];
	fstream fmat;
	int i, j;
	for( i = 0; i <= kol - 1; i++ )
		for( j = 0; j <= red - 1; j++ )
			matrix[i][j] = random(1000);
	for( i = 0; i <= kol - 1; i++ )
		for( j = 0; j <= red - 1; j++ )
		{
			if( matrix[i][j] < 10 )
			{
				matrix[i][j] *= 100;
			}
			if( matrix[i][j] < 100 )
			{
				matrix[i][j] *= 10;
			}
		}
	cout << "Vnesete ja patekata na fajlot:";
	cin >> path;
	fmat.open(path);
	if( !fmat )
	{
		cout << "Greeska" << endl;
	}
	else
	{
		for( i = 0; i <= kol - 1; i++ )
		{
			for( j = 0; j <= red - 1; j++ )
				fmat << matrix[i][j] << ' ';
			fmat << endl;
		}
		fmat.close();
	}
}

void loadmatrix()
{
	char path[100], zn;
	ifstream f;
	int i = 0, j = 0, br;
	cout << "Vnesete ja patekata:";
	cin >> path;
	f.open(path);
	while( !f.eof() )
	{
		f >> matrix[i][j];
		j++;
		if( j >= 3 )
		{
			i++;
			j = 0;
		}
	}
	f.close();
}

void resetni()
{
	ni[0] = 'q'; ni[1] = 'a'; ni[2] = 'e'; ni[3] = 'g';
	ni[4] = 'f';
	ni[5] = 'm';
	ni[6] = 'p';
	ni[7] = 'r';
	ni[8] = 'b';
	ni[9] = 'z';
	ni[10] = 'c';
	ni[11] = 'x';
	ni[12] = 'l';
	ni[13] = ' ';
	ni[14] = 'i';
	ni[15] = 'v';
	ni[16] = 'y';
	ni[17] = 'd';
	ni[18] = 'n';
	ni[19] = 'k';
	ni[20] = 's';
	ni[21] = 'j';
	ni[22] = 'b';
	ni[23] = 'h';
	ni[24] = 'u';
	ni[25] = 'o';
	ni[26] = 't';
	ni[27] = '_';
}


void findchar()
{
	int i;
	resetni();
	for( i = 0; i <= dim; i++ )
	{
		niza[i] = ni[matindex[i]];
		pomestides();
	}
}


void pomestidesno()
{
	int i, j;
	for( i = 0; i <= 2; i++ )
	{
		if( dolzinp != 3 )
		{
			for( j = 0; j <= dolzinp - 2; j++ )
			{
				inputencrarr[j] = inputencrarr[j + 1];
			}
			dolzinp--;
		}
	}
}

void findindex()
{
	bool inlin;
	int i, j, k, l = 0;
	k = dolzinp;
	while( k != 0 )
	{
		for( i = 0; i <= kol - 1; i++ )
		{
			if( k != 0 )
			{
				inlin = true;
				for( j = 0; j <= red - 1; j++ )
				{
					if( matrix[i][j] != inputencrarr[j] )
					{
						inlin = false;
					}
				}
				if( inlin == true )
				{
					matindex[l] = i;
					l++;
					pomestidesno();
					k = k - 3;
				}
			}
			else
			{
				dim = l - 1;
				return;
			}
		}
	}
	dim = l - 1;
}

void readencriptionfile()
{
	ifstream f;
	uint a, b, c, i = 0;
	char path[100];
	dolzinp = 0;
	cout << "Vnsete ja patekata na enkriptiraniot fajl:";
	cin >> path;
	f.open(path);
	if( !f )
	{
		cout << "Greska" << endl;
	}
	else
	{
		while( !f.eof() )
		{
			f >> inputencrarr[i];
			i++;
			dolzinp++;
		}
	}
	f.close();
	dolzinp -= 1;
	cout << "Ja vcitevte nizata:" << endl;
	for( i = 0; i <= dolzinp - 1; i++ )
		cout << inputencrarr[i] << " - ";
	cout << endl;
	findindex();
	findchar();
	cout << "Posle dekriptiranjeto dobivte:";
	cout << niza;
	system("pause");
}

void decriptmatrix()
{
	char izb;
	int i;
	do
	{
		clrscr();
		cout << "1.Vnesuvanje na enkriptirana poraka preku tastatura" << endl;
		cout << "2.Vcituvanje na enkriptiran fajl" << endl;
		cout << "0.Izlez" << endl;
		izb = getch();
		switch( izb )
		{
		case '1':
		{
			cout << "Kolku broevi ke vnesete?:";
			cin >> dolzinp;
			for( i = 0; i <= dolzinp - 1; i++ )
			{
				cout << "-" << i << "-";
				cin >> inputencrarr[i];
				cout << endl;
			}
			findindex();
			findchar();
			cout << "Posle dekriptiranjeto dobivte:";
			cout << niza;
			system("pause");
		}
		case '2':
		{
			readencriptionfile();
		}
		}
	}
	while( izb != '0' );
}

void izbor1()
{
	char izb1, izb2;
	do
	{
		clrscr();
		cout << "Mod na enkirpcija:" << endl;
		cout << "1.Redosledna matrica" << endl;
		cout << "2.Matrica so slucajno izbrani broevi" << endl;
		cout << "0.Izlez" << endl;
		izb1 = getch();
		izb1 = toupper(izb1);
		switch( izb1 )
		{
		case '1':
		{
			genmat();
			printmat();
			system("pause");
			break;
		}
		case'2':
		{
			do
			{
				clrscr();
				cout << "1.Generiranje na nova matrica" << endl;
				cout << "2.Vcituvanje na matrica od fajl" << endl;
				izb2 = getch();
			}
			while( izb2 != '1' && izb2 != '2' );
			if( izb2 == '1' )
			{
				genrandomatrix();
				cout << "Ja generiravte matricata:" << endl;
				printmat();
				system("pause");
			}
			else
			{
				loadmatrix();
				cout << "Ja vcitavte matricata:" << endl;
				printmat();
				system("pause");
			}
			break;
		}
		}
	}
	while( izb1 != '0' );
	encodearr();
	printencodearr();
	system("pause");
}

void izbor2()
{
	char izb1, izb2;
	do
	{
		clrscr();
		cout << "1.Redosledna matrica" << endl;
		cout << "2.Matrica so slucajno izbrani brovi" << endl;
		cout << "0.Izlez" << endl;
		izb1 = getch();
		switch( izb1 )
		{
		case '1':
		{
			genmat();
			printmat();
			system("pause");
			break;
		}
		}
	}
	while( izb1 != '0' );
	decriptmatrix();
}


int main(int argc, char* argv[])
{
	char izb;
	do
	{
		clrscr();
		cout << "1.Enkripcija" << endl;
		cout << "2.Dekripcija" << endl;
		cout << "0.Izlez" << endl;
		izb = getch();
		switch( izb )
		{
		case '1':
		{
			izbor1();
			break;
		}
		case '2':
		{
			izbor2();
			break;
		}
		}
	}
	while( izb != '0' );
	system("pause");

	return 0;
}
#endif