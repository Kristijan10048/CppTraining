#ifdef NOT_FIXED

#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#include <string.h>
#include <locale>

string text;
int i, j, n;

#pragma argsused
int main(int argc, char* argv[])
{
	cout << "Vnesi go tekstot vo koj treba da se baraat iminja";
	cin >> text;
	n = text.length();
	i = 0;
	while( i <= n )
	{
		if( (text[i] == ' ') && (text[i + 1] == toupper(text[i + 1])) )
		{
			cout << "Ime" << endl;
		}
		i++;
	}

	int g;
	cin >> g;
	return 0;
}
#endif
