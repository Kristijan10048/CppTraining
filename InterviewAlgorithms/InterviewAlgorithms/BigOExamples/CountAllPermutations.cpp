#include <iostream>
#include <string>

using namespace std;

//function declaration
void Permutation(string str, string prefix);
void Permutation(string str);

void Permutation(int callNo, string str, string prefix) 
{
	cout<<"Call:"<<callNo<<endl;
	if (str.length() == 0) 
	{
		cout<<"-----------------------------------------"<<endl;
		cout<<"Prefix :"<<prefix<<endl;
		cout<<"-----------------------------------------"<<endl;
	} 
	else 
	{
		for (int i = 0; i < str.length(); i++) 
		{
			//get substring 0 to i
			string s1 = str.substr(0, i);
			string s2 = str.substr(i + 1);
			
			string rem = str.substr(0, i) + str.substr(i + 1);
			
			cout<<"****************"<<endl;
			cout<<"Loop:"<<i<<endl;
			cout<<"String :"<<str<<endl;
			cout<<"Prefix :"<<prefix<<" + "<<str[i]<<endl;
			cout<<"Substr 0 to "<<i<<": "<<s1<<endl;
			cout<<"Substr "<<i<<" + 1: "<<s2<<endl;
			cout<<"rem: "<<rem<<endl;
			cout<<"****************"<<endl;
			callNo++;
			Permutation(callNo, rem, prefix + str[i]); //+ str.charAt(i
		}
	}
}

void Permutation(string str) 
{
	Permutation(0, str, "");
}

int main(int argc, char* argv[])
{
	//process input
	if(argc != 2 )
	{
		cout<<"Wrong number of arguments!"<<endl;
		return 0;
	}
	
	
	//create a string
	string s(argv[1]);
	
	//calculate permutations
	Permutation(s);
}
