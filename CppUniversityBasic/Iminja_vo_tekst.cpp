#ifdef NOT_FIXED

#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#include <string.h>

string text;
int i, j, n;

#pragma argsused
int main(int argc, char* argv[])
{
	cout << "Vnesi go tekstot vo koj treba da se baraat iminja";
	cin >> text;
	n = text.length();
	while( i <= n )
	{
		if( text[i] == ' ' && text[i + 1] == toupper(text[i + 1]) )
		{
			cout << "Ime" << endl;
		}
	}
	return 0;
}
#endif