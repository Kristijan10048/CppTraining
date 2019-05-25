#include <iostream>
#include <set>
using namespace std;

//prints the contet of a given set
void PrintSet(std::set<int> set)
{
	//iterators
	for (auto it = set.begin(); it != set.end(); ++it)
		cout<<"Set element :"<<*it<<endl;
		
	cout<<endl;
}

//prints the contet of a given set
void PrintSetInReverse(std::set<int> set)
{
	//iterators
	for (auto it = set.rbegin(); it != set.rend(); ++it)
		cout<<"Set element :"<<*it<<endl;
		
	cout<<endl;
}

//inserts numbers 10 - 14 in to the set
void InsertElements(std::set<int> *set)
{
	for(int i = 10; i<15;i++)
		set->insert(i);
}

void main()
{
	std::set<int> mySet = {1, 3, 5, 6, 7};
	
	//prints the content of the set
	PrintSet(mySet);
	
	//inserts some elements in the set
	InsertElements(&mySet);
	
	//prints the content of the set
	//state of the set after insersion
	PrintSet(mySet);
	
	cout<<"Reverse print of the set"<<endl;
	PrintSetInReverse(mySet);
}