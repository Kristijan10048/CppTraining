#include <iostream>

#include <utility>

using namespace std;

void main()
{
	std::pair<int, int> myPair;
	myPair.first =10;
	myPair.second = -15;
	
	cout<<"Pair ("<<myPair.first<<", "<<myPair.second<<")"<<endl;
	
	//dynamicly create pair object
	std::pair<int, int> *pPair = new std::pair<int, int>(1,2);
	
	//accces members
	cout<<"Dynamic pair:"<< pPair->first<<", "<<pPair->second<<endl;
	
	//swap elements
	pPair->swap(myPair);
	
	//print after swaping
	cout<<"Dynamic pair after swaping:"<< pPair->first<<", "<<pPair->second<<endl;
	
	//delete object
	delete pPair;
}