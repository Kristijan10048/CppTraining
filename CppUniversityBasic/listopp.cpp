#ifdef NOT_FIXED

#include<iostream>
#include<stdlib.h>
#include<conio.h>
#define nil 0

struct lista
{
	int br;
	lista* sleden;
};

lista* vnesiel(lista* prv);
lista* vnesiel(lista* prv)
{
	lista* temp, * tek;
	char zn;
	do
	{
		clrscr();
		temp = new lista;
		cout << "Broj:";
		cin >> temp->br;
		temp->sleden = nil;
		if( prv == nil )
			prv = temp;
		else
		{
			tek = new lista;
			tek = prv;
			while( tek->sleden != nil )
				tek = tek->sleden;
			tek->sleden = temp;
		}
		cout << "Dali sakas uste da vnesuvas?D/N";
		zn = getch();
		zn = toupper(zn);
	}
	while( zn == 'D' );
	return(prv);
}

void printlist(lista* prv1);
void printlist(lista* prv1)
{
	if( prv1 != nil )
	{
		cout << prv1->br << "->";
		printlist(prv1->sleden);
	}
}

lista* spoi(lista* prv1, lista* prv2);
lista* spoi(lista* prv1, lista* prv2)
{
	lista* temp, * pa;
	temp = new lista;
	pa = new lista;
	temp = prv1;
	pa = temp;
	while( temp->sleden != nil )
		temp = temp->sleden;
	temp->sleden = prv2;
	return(pa);
}

void sortlist(lista* prv, int pati);
void sortlist(lista* prv, int pati)
{
	lista* temp, * temp1;
	int pom;
	temp = prv;
	temp1 = temp;
	temp1 = temp1->sleden;
	while( temp->sleden != nil )
	{
		if( temp->br > temp1->br )
		{
			pom = temp->br;
			temp->br = temp1->br;
			temp1->br = pom;
		}
		temp = temp->sleden;
		temp1 = temp1->sleden;
	}
	if( pati != 3 )
		sortlist(prv, pati + 1);
}

void reductlist(lista* prv);
void reductlist(lista* prv)
{
	lista* temp, * temp1, * ptemp1;
	temp = prv;
	while( temp->sleden != nil )
	{
		temp1 = temp->sleden;
		while( temp1->sleden != nil )
		{
			ptemp1 = temp1;
			ptemp1 = ptemp1->sleden;
			if( temp->br == ptemp1->br )
			{
				temp1->sleden = ptemp1->sleden;
			}
		}
		temp = temp->sleden;
	}
}

bool prost(int br);
bool prost(int br)
{
	int i = 2;
	if( br == 3 )
		return(false);
	while( i != br / 2 )
	{
		if( br % i == 0 )
			return(false);
		i++;
	}
	return(true);
}

void posleprost(lista* prv);
void posleprost(lista* prv)
{
	lista* temp, * temp1;
	temp = new lista;
	if( prv == nil )
		return;
	else
	{
		temp = prv;
		while( temp->sleden != nil )
		{
			temp1 = temp;
			temp = temp->sleden;
			if( prost(temp1->br) == true )
				temp1->sleden = temp->sleden;

		}
	}
}

int main(int argc, char* argv[])
{
	lista* ank1, * ank2, * ank3;
	ank1 = nil;
	ank2 = nil;
	ank3 = nil;
	char zn, izb;
	do
	{
		clrscr();
		cout << "1.Vnesuvanje na elementite od listata" << endl
			<< "2.Vnesuvanje na elementite od vtorata lista" << endl
			<< "3.Sortiranje na listata" << endl
			<< "4.Redukcija na elementi koi se povtoruvaat" << endl
			<< "5.Redukcija na elmenti pred prost broj" << endl
			<< "6.Spojuvanje na dvete listi" << endl
			<< "7.Pecatenje ne elementite od listite" << endl
			<< "0.Izlez" << endl;
		zn = getch();
		switch( zn )
		{
		case '1':
		{
			clrscr();
			cout << "Nova nizaD/N?";
			izb = getch();
			izb = toupper(izb);
			if( izb == 'D' )
			{
				ank1 = nil;
				ank1 = vnesiel(ank1);
			}
			else
				ank1 = vnesiel(ank1);
			break;
		}

		case '2':
		{
			clrscr();
			cout << "Nova nizaD/N?";
			izb = getch();
			izb = toupper(izb);
			if( izb == 'D' )
			{
				ank2 = nil;
				ank2 = vnesiel(ank2);
			}
			else
				ank2 = vnesiel(ank2);
			break;
		}
		case '3':
		{
			sortlist(ank1, 1);
			break;
		}
		case '4':
		{
			reductlist(ank1);
			break;
		}
		case '5':
		{
			posleprost(ank1);
			break;
		}
		case '6':
		{
			if( ank1 != nil && ank2 != nil )
			{
				ank3 = spoi(ank1, ank2);
				cout << "Dvete listi spoeni:\n";
				printlist(ank3);
				system("pause");
			}
			else
			{
				cout << "listite se prazni";
				system("pasue");
			}
			break;
		}
		case '7':
		{
			clrscr();
			cout << "Prvata lista:";
			printlist(ank1);
			cout << endl << "Vtorata lista:";
			printlist(ank2);
			system("pause");
			break;
		}
		}
	}
	while( zn != '0' );
	return 0;
}
#endif;
