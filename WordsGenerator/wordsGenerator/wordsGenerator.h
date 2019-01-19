#include "stdafx.h"
#include <iostream>
#include <fstream> 
#include <string>
#include <windows.h> 
#include <tchar.h>

using namespace std;

#ifndef WORDSGENERATOR_H_INCLUDED
#define WORDSGENERATOR_H_INCLUDED

/**
* a normal member taking two arguments and returning an integer value
*
* @param a an integer argument.
* @param s a constant character pointer.
* @see Javadoc_Test()
*
* @return The test results
*/
void FunctionTemplate(int param1, int param2);

//	A function that checks if two adjesent charatres are same
//
//param: inp input string
bool HasDoubleLetter(string inp);

void WordGenerator(string fn, int len);
#endif
