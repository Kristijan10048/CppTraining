#ifdef NOT_FIXED

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
int dol;
struct niza
{
	int br;
	int pati;
}ni[20];

void inparr();
void inparr()
{
	int i;
	cout << "Kolku elementi ima nizata?" << endl;
	cin >> dol;
	for( i = 0; i <= dol - 1; i++ )
	{
		cout << "ni[" << i << "]=";
		cin >> ni[i].br;
		cout << endl;
	}
}
int povtoruvanja(int br1);
int povtoruvanja(int br1)
{
	int i, pati = 0;
	for( i = 0; i <= dol - 1; i++ )
	{
		if( ni[i].br == br1 )
		{
			pati++;
		}
	}
	return(pati);
}

void vnesipovt();
void vnesipovt()
{
	int i;
	for( i = 0; i <= dol - 1; i++ )
		ni[i].pati = povtoruvanja(ni[i].br);

}

void swapni();
void swapni()
{
	niza pom;
	int n = dol - 1, i;
	for( i = 0; i <= n / 2; i++ )
	{
		pom = ni[i];
		ni[i] = ni[n - i];
		ni[n - i] = pom;
	}
}
void sortni();
void sortni()
{
	int i, j;
	niza pom;
	vnesipovt();
	for( i = 0; i <= 2 * dol - 1; i++ )
		for( j = dol - 2; j >= 0; j-- )
		{
			if( ni[j].pati > ni[j + 1].pati )
			{
				pom = ni[j];
				ni[j] = ni[j + 1];
				ni[j + 1] = pom;
			}
		}
}

void printni();
void printni()
{
	int i;
	for( i = 0; i <= dol - 1; i++ )
		cout << ni[i].br << " ";
}
int main(int argc, char* argv[])

{
	inparr();
	cout << "Sortirana niza" << endl;
	sortni();
	printni();
	cout << "prev" << endl;
	swapni();
	printni();
	system("pause");

	return 0;
}
//---------------------------------------------------------------------------
#endif