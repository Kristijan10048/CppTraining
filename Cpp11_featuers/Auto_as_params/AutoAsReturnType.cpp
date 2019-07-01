#include <iostream>
#include <string>

using namespace std;

//simple implementation of abstract class
class Object
{
	
	public :
		//createion of pure abstract class.
		virtual string toString() = 0;
};

//a simple base class
class Base{
	
	private : 
		int m_someNumb = 10;;
		
	protected :
		string m_name;
		
	public :
		//constructor
		Base(string name)
		{
			this->m_name = name;
		}
		
		//Pritns class data
		virtual void PrintMe()
		{
			cout << "Number :" << m_someNumb <<", name :"<<m_name<<endl;
		}
};

// a simple drievd class
class Person : Base
{
	private : 
		string m_lastName;
		int m_age = 0;
	public:
		//constructor
		Person(string name, string lastName) :Base(name)
		{
			this->m_lastName = lastName;
		}
	
		//simple setter using auto as parameter 	
		void SetAge(int age) {this->m_age = age;}
		
		//using auto as return type of a function
		auto GetAge() {return this->m_age;}
		
		//override
		void PrintMe()
		{
			cout<<"Name:"<<m_name<<", Last name:"<<m_lastName<<endl;
			cout<<"Age: "<<GetAge()<<endl;
		}
};


int main(int argc, const char* argv)
{
	//create object of a base class
	Base *b1 = new Base("Test");
	
	auto obj = b1;
	
	//calls PrintMe() of the base class
	obj->PrintMe();
	
	//create new derived class object
	Person *p = new Person("Test", "Testovski");
	
	//assign p to auto obj 
	auto obj1 = p;
	
	//calls PrintMe() of the derived class
	obj1->PrintMe();
	
	delete b1, p;
	return 0;
}