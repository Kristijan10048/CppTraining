# include <iostream>
# include <string.h>
# include <conio.h>


using namespace std;


int main1(int argc, char* argv[])
{
	string s, s1 = "123";
	char zn;
	cout << "vnesi string" << endl;
	cin >> s;
	cout << s << "," << s1;
	cout << "Vnesi znak" << endl;
	cin >> zn;
	s.insert(1, 1, zn);
	cout << s;
	s.clear();

	_getch();
	return 0;
}