#include <iostream>
#include <string>

using namespace std;

//simple class for cpp
class BaseClassA
{
	int number;
	std::string address;

	public :
		BaseClassA(int number,std::string address);
		void Print() {cout<<"Number:"<<number<<" Address:"<<address<<endl;}
		
};

//constructor
BaseClassA::BaseClassA(int number, std::string address)
{
	this->number = number;
	this->address = address;
}

int main(int arc, const char* argv)
{
	BaseClassA obj1(11, "test");
	
	//use auto to automatically get the type
	auto unkn = obj1;
	
	
	unkn.Print();
	return 0;
}