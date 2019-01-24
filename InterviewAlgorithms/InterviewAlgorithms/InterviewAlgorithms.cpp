// InterviewAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

//Cracking the code intervew
/*
	1.1  Chekcs if given string contains unique characters
*/
void IsUnique()
{
	const int C_BUFF_LEN = 255;

	//alocate space for unique chars
	char tmpBuff[C_BUFF_LEN];

	string inpBuff = "123~!@#$%^tes"; //"this is not unique!";	

	cout << "Running IsUnique" << endl;
	for (int i = 0; i < inpBuff.length(); i++)
	{
		char currCh = inpBuff[i];
		//result is from 0 - 511
		int currChIndex = (int)currCh % C_BUFF_LEN;

		//create pseudo hash table where key is (int)currCh % C_BUFF_LEN
		if (currCh != tmpBuff[currChIndex])
		{
			tmpBuff[currChIndex] = currCh;
		}
		else
		{
			cout << "Duplicate found :" << currCh << endl;
			return;
		}
	}

	cout << "Input : " << inpBuff << "is unique!!!" << endl;
}

/*
	1.3 Replaceses spacees in a string with %20
*/
void Urlfy(string url)
{
	string tmpBuff;

	int counter = 0;
	cout << "Input :" << url << endl;
	for (int i = 0; i < url.length(); i++)
	{
		if (url[i] != ' ')
		{
			tmpBuff.append(1, url[i]);
		}
		else
		{
			tmpBuff.append(1, '%');
			tmpBuff.append(1, '2');
			tmpBuff.append(1, '0');
		}
	}

	cout << "Output :" << tmpBuff << endl;
}

/*pritns ount even or
odd for given number*/
void EvenOrOdd()
{
	std::cout << "Hello World!\n";
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			cout << "Even :" << i << endl;
		else
			cout << "Odd :" << i << endl;
	}

}


int main()
{
	Urlfy("test bla bla");

	IsUnique();

	int t;
	cin >> t;
}