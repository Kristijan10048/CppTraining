// InterviewAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

/*
Replaceses space with %20
*/
void Urlfy(string url)
{
	string tmpBuff = "";
	
	int counter = 0;
	for (int i = 0; i < url.length(); i++)
	{
		if (url[i] != ' ')
		{
			tmpBuff[counter] = url[counter];
			counter++;
		}
		else
		{
			tmpBuff[counter] = '%';
			counter++;
			tmpBuff[counter] = '2';
			counter++;
			tmpBuff[counter] = '0';
		}


	}

	cout << tmpBuff << endl;
}

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

	int t;
	cin >> t;
}