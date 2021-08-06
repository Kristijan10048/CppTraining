#include <iostream>
#include <list>

using namespace std;

//const keyword means that the function is not changing the argument
void PrintList(const std::list<int> &list)
{
	for(int it:list)
		cout<<"Element :"<<it<<endl;
}

void MainList()
{
	std::list<int> lst = {2, 3, 5, 7};

	//prints inital state of the list
	PrintList(lst);
	
	lst.push_back(11);
	lst.push_back(12);
	
	cout<<"List state after push_back call:"<<endl;
	PrintList(lst);
}