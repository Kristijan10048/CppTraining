/*
 * SwapValues.cpp
 *
 *  Created on: Jan 2, 2018
 *      Author: kris
 */

#include <iostream>
using namespace std;

int main()
{

	int val1 = 1;
	int val2 =45;
	int tmpVal;

	//store first variable
	tmpVal = val1;

	//copy second variable to first one
	val1 = val2;

	//copy temp to second variable
    val2 = tmpVal;
	return 0;
}
