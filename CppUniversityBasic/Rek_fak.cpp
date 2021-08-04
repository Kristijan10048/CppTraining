#include<iostream>
#include<stdlib.h>

using namespace std;

void faktoriel(int br, int& f);
void faktoriel(int br, int& f)
{
	if( br != 0 )
	{
		f = f * br;
		faktoriel(br - 1, f);
	}
}
void nrek(int br)
{
	if( br != 0 )
	{
		cout << br << ", ";
		nrek(br - 1);
		cout << br << ", ";
	}
}

int mainREK_FAK(int argc, char* argv[])
{
	cout << "N=";
	int n, fa = 1;
	cin >> n;
	nrek(n);
	cout << endl << "Faktoriel" << endl;
	cin >> n;
	cout << n;
	faktoriel(n, fa);
	cout << "Faktoriel:" << fa;
	system("pause");

	return 0;
}
//---------------------------------------------------------------------------
