// InterviewAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include <iostream>
#include <string>
#include <cstdio>
#include <unordered_map>



using namespace std;

/***********************************************************************************	
			 Cracking the Coding Interview - 2016
					Gayle Laakmann McDowell
************************************************************************************/

/*using of hash table in c++
std::unordered_map<char, int> hash;
char ch = 't';
hash.insert({ ch, (int)ch });
get pairs p
for (auto& p : hash)
	cout << "First:" << p.first << " Last:" << p.second << endl;

Return value
Iterator to an element with key equivalent to key.If no such element is found, past - the - end(see end()) iterator is returned.

auto search = hash.find('t');
if (search != hash.end()) {
	std::cout << "Found " << search->first << " " << search->second << '\n';
}
else {
	std::cout << "Not found\n";
}*/


//Cracking the code interview
/*
	1.1  Checks if given string contains unique characters
*/
void IsUnique()
{
	string s;

	const int C_BUFF_LEN = 255;

	//allocate space for unique chars
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
	1.2 Given two strings, write a method do decide if one is a permutation of the other
*/
void CheckPermutation()
{
	string param1 = "abc";
	string param2 = "bca";

	string tmpBuff = param1 + param1;

	int res = tmpBuff.find(param2);
}

/*
	1.3 Replaces spaces in a string with %20
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

/*
	Given a string, write a function to check if it is a permutation of a palindrome.
	A palindrome is a word or phrase that is the same forwards and backwards. The palindrome does not
	need to be limited to just dictionary words.
*/
void PalindromePermutation()
{
	string inpData = "ttat41tatt";

	const int C_BUFF_MAX = 256;
	int tmpBufer[C_BUFF_MAX];

	//set the tmp container to 0
	for (int i = 0; i < C_BUFF_MAX; i++)
		tmpBufer[i] = 0;

	//store the count of all chars in to a hash table
	for (int i = 0; i < inpData.length(); i++)
	{
		int currIndex = (int)inpData[i] % C_BUFF_MAX;
		tmpBufer[currIndex]++;
	}

	//check the count of odd characters 
	int oddCount = 0;
	for (int i = 0; i < C_BUFF_MAX; i++)
	{
		if (tmpBufer[i] % 2 == 1)
		{
			oddCount++;
		}
	}

	if (oddCount > 1)
		cout << "The word is NOT palindrome permutation!" << endl;
	else
		cout << "The word is palindrome permutation!" << endl;
}

/*prints out even or
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

//One Away : There are three types of edits that can be performed on strings : insert a character,
//remove a character, or replace a character.Given two strings, write a function to check if they are
//one edit(or zero edits) away
void OneAway()
{
	string sInp = "test";
	string sTest = "ts";
	bool res;

	char buff[100];
	//snprintf(buff, sizeof(buff), "%s, %s -> %B", "Hello");
	//std::string buffAsStdStr = buff;


	if (abs(static_cast<int>(sInp.length() - sTest.length())) > 1)
	{
		res = false;
		snprintf(buff, sizeof(buff), "%s, %s ->", sInp, sTest);
		printf(buff);
	}

}

//int main()
//{
//	//Urlfy("test bla bla");
//	//CheckPermutation();
//	//IsUnique();
//	//PalindromePermutation();
//
//	OneAway();
//}


TEST_CASE("exceptions", "") {
}