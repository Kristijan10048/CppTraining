#include <conio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>


using namespace std;
string s;

bool palindrom(string st);
void substr();

/// <summary>
/// Checks if given string is palindrome
/// </summary>
/// <param name="st"></param>
/// <returns></returns>
bool palindrom(string st)
{
	int i, dol;
	dol = st.length();
	for( i = 0; i <= (dol - 1) / 2; i++ )
		if( st[i] != st[dol - 1 - i] )
			return(false);
	return(true);
}


void substr()
{
	int i, j, k, dol;
	dol = s.length();
	string pom;
	for( k = 1; k <= dol - 1; k++ )
	{
		for( i = 0; i <= dol - 1 - k; i++ )
		{
			pom.clear();
			for( j = i; j <= i + k; j++ )
			{
				pom = pom + s[j];
				cout << s[j];
			}
			if( palindrom(pom) == true )
				cout << "---Podnizata go ima baraniot oblik" << endl;
			cout << endl;
		}
	}
}


int main2(int argc, char* argv[])
{
	cout << "Text";
	cin >> s;
	substr();
	system("pause");

	return 0;
}