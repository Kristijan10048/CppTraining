#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;

int ConvertFromBase(string number, int base);

bool CompareBinWithHex(string binary, string hex) 
{
	int n1 = ConvertFromBase(binary, 2);
	int n2 = ConvertFromBase(hex, 16);
	if (n1 < 0 || n2 < 0)
		return false;
	
	return n1 == n2;
 }

int ConvertFromBase(string number, int base) 
{
	if (base < 2 || (base> 10 && base != 16) ) 
		return -10;
	
	int value = 0;
	for (int i = number.length() - 1; i >= 0; i--) 
	{
		const char c = number[i];
		int digit = atoi(&c);
		
		cout<<"digit :"<<digit<<endl;
		
		if (digit < 0 || digit >= base)
			return -1;
 
		int exp = number.length() - 1 - i;
		
		value += digit * pow(base, exp);
		
		cout<<"value"<<value<<endl;
	}
	
	return value;
 }
 
int main(int argc, char *argv[])
{
	
	
	
	if(argc != 3)
	{
		cout<<"Wrong number of arguments!"<<endl;
		return -1;
	}
	
	
	
	int base = atoi(argv[2]);
	string number(argv[1]);
	
	cout<<"Number :"<<atoi(argv[2]);
	cout<<" Base:"<<base<<endl;
	
	int res = ConvertFromBase(number, base);
	 
	cout<<"Res :"<<res<<endl;
}