#include <iostream>
#include <map>


using namespace std;

//prins all elements from a map: key, value
void PrintMap(std::map<int, int> *map)
{
	//loop over all elements in the map
	for(auto it = map->begin(); it!=map->end(); ++it)
		cout<<"key :"<<it->first<<" value :"<<it->second<<endl;
}

void main()
{
	std::map<int, int> *map = new std::map<int, int>();
	
	//populate map. Insert takes key, value pair
	for(int i = 0; i < 15; i++)
	{
		map->insert(pair<int, int>(i, 255+i));
	}
	
	//print the content of the map
	PrintMap(map);
	
	//when pointers are used its complcicated to  use [] operator
	std::map<int, int> &testm=*map;
	
	//add element using [] operator
	testm[0] = -11;		
	testm[16] = -12;
	testm[17] = -13;
	
	//print map after insertion
	cout<<endl<<"Map state after insertion:"<<endl;
	PrintMap(map);
	
	//celan up memory
	delete map;
}