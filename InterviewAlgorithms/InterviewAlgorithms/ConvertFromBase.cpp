#include <string.h>
#include <iostream>

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
	if (base < 2 || (base> 10 && base != 16)) 
		return -1;
	
	int value = 0;
	for (int i = number.length() - 1; i >= 0; i--) 
	{
		int digit = atoi(&number[i]);
		
		if (digit < 0 || digit >= base)
			return -1;
 
		int exp = number.length() - 1 - i;
		
		value += digit * Math.pow(base, exp);
	}
 return value;
 }
 
int main(int argc, char *argv[])
{
	 int res = ConvertFromBase("1010",2);
	 
	 cout<<"Res :"<<res<<endl;
}