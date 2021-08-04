#ifdef NOT_FIXED
#pragma hdrstop
#pragma argsused
#include <iostream>
#include <conio.h>
#include <string.h>
#define nil 0

struct lists
{
	int unsigned index;
	string dat;
	lists* next;
};
void vnsi();
void printlist();

lists* ank, * sled, * tek;


void vnesi(int in)
{
	if( ank == nil )
	{
		cout << "Vnesi podatok:";
		lists* tek = new lists;
		cin >> tek->dat;
		tek->index = 1;
		ank = tek;
	}
	else
	{
		sled = tek;
		lists* tek = new lists;
		cout << "Vnesi podatok:";
		cin >> tek->dat;
		tek->index = in;
	}
}

void printlist()
{
	tek = ank;
	while( tek->next != nil )
	{
		cout << tek->dat << "index--" << tek->index;
		tek = tek->next;
	}
}

int main(int argc, char* argv[])
{
	int i = 2;
	char zn;
	ank = nil;
	do
	{
		vnesi(i);
		cout << "Dali sakate da vnesuvate uste (D/N)";
		zn = getch();
		zn = toupper(zn);
		i++;
	}
	while( zn == 'D' );
	cout << endl << "Listata isprintana izgleda vaka:";
	printlist();
	getch();

	return 0;
}
#endif