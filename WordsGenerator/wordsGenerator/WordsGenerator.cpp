#include "stdafx.h"
#include "wordsGenerator.h"

using namespace std;
///this is implementation of the template
void FunctionTemplate(int param1, int param2)
{

}

//	A function that checks if two adjesent charatres are same
//
// param: inp input string
bool HasDoubleLetter(string inp)
{
	unsigned int i;
	for (i = 0; i < inp.length() - 1; i++)
		if (inp[i] == inp[i + 1])
			return true;
	return false;
}

/// <summary>
///	A function that generates words with given length
//
/// param: fn beginning string
/// param: len word length
/// </summary>
void WordGenerator(string fn, int len)
{

	//dolzina na zbor:len
	int i, j = 0;

	//poceten string
	string str;

	//string za kompracacija
	string cmpstr;

	//karakter za terminiranje
	char trm = 'z';

	//otvaranje na fajl za zapisuvanje
	ofstream fwriter;

	fwriter.open("");
	if (!fwriter)
	{
		cout << "Error oppening source file: " << fn << endl;
		system("pause");
		return;
	}

	//inicijalizacija na stringovite
	for (i = 0; i < len; i++)
	{
		str = str + "a";
		cmpstr = cmpstr + "a";
	}

	//stringot za terminirane e aaa}
	//koga ke se zgolemi zzzz+1 se 
	//dobiva aaaa(trm+1)
	cmpstr[len - 1] = char(trm + 1);

	int k = 0;
	while ((str != cmpstr))
	{
		for (i = 0; i < 26; i++)
		{
			fwriter << str << "\n";
			str[0] = (char)((int)str[0] + 1);
		}

		k = 0;
		while ((str[k] > trm) && (k != len - 1))
		{
			str[k] = 'a';
			str[k + 1] = (char)(str[k + 1] + 1);
			k++;
		}

	}
	fwriter.close();
}
