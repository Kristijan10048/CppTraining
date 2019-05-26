#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
//stof searches for first number in the string and converts
void main()
{
	//convert string to integer
	const char *number_str = "10";
    cout << "The string is: " << number_str << endl;
	double numb = stof(number_str);
	cout << "The number is: " << numb <<endl;
	
	//floating point is truncated
	const char *number_str1 = "w 6  12.34567 d"; //"w 6  12.34567 d"; falls
	cout << "The string is: " << number_str1 << endl;
	double numb1 = stof(number_str1);
	cout << "The number is: " << numb1 <<endl;
}