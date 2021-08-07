#include<iostream>
#include<vector>

using namespace std;

int MainAutoKeyword(int argc, const char * argv[])
{
	vector<int> myVect;
	const int c_max = 10;
	
	//fill the vector with values
	for(int i = 0; i < c_max; i++)
	{
		myVect.push_back(i);
	}
	
	//using the old way to loop
	cout<<"Stanard cpp synatax:"<<endl;
	typename  std::vector<int>::iterator it;
	for(it = myVect.begin(); it != myVect.end(); ++it)
	{
		cout<<*it<<", ";
	}
	cout<<endl;

	//usin auto keyword to iterate in to vector container
	cout<<"Same thing as above just using auto keyword:"<<endl;
	for(auto it =myVect.begin(); it != myVect.end(); ++it)
	{
		cout<<*it<<", ";
	}
	
	
	return 0;
}