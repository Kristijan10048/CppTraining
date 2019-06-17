#include <iostream>
#include <cstdlib>

using namespace std;

void main()
{
	//convert string to integer
	const char *number_str = "10";
    cout << "The string is: " << number_str << endl;
	double numb = atof(number_str);
	cout << "The number is: " << numb <<endl;
	
	//floating point is truncated
	const char *number_str1 = "12.34567";
	cout << "The string is: " << number_str1 << endl;
	double numb1 = atof(number_str1);
	cout << "The number is: " << numb1 <<endl;
}