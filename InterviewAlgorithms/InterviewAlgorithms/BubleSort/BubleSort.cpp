#include <iostream>

using namespace std;

int main()
{
	int tmpArr[] = {4, 5, 1, 2, 3, 6};
	const int c_max = 6;
	
	cout<<"Initial state of the array:"<<endl;
	for(int i = 0; i < c_max; i++)
		cout<<tmpArr[i]<<",";
	
	cout<<endl;
	
	//do the buble sort
	for(int i = 0; i < c_max; i++)
		for(int j = i + 1; j < c_max; j++)
		{
			if(tmpArr[i] > tmpArr[j])
			{
				int tmp = tmpArr[i];
				tmpArr[i] = tmpArr[j];
				tmpArr[j] = tmp;
			}
		}
	
	cout<<"State of the array after buble sort :"<<endl;
	for(int i = 0; i < c_max; i++)
		cout<<tmpArr[i]<<",";
	
	return 0;
}