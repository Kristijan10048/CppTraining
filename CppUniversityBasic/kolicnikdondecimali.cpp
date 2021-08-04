#ifdef NOT_FIXED
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	cout << "Vnesi nekoj broj" << endl;
	float kol, ost, ost1;
	int n, i, a, b, k;
	cin >> a;
	cout << "Vnesi broj so koj sakas da go podelis" << endl;
	cin >> b;
	cout << "Na kolku decimali sakas da bide kolicnikot?" << endl;
	cin >> n;
	kol = a / b;
	k = 10;
	for( i = 1; i <= n; i++ )
	{
		a = a % b;
		a = a * 10;
		ost = (a / b);
		ost1 = ost / k;
		cout << "a=" << a << "ost1" << ost1 << endl;
		kol = kol + ost1;
		cout << kol << "  ";
		k = k * 10;
	}

	cout << "Kolicnikot iznesuva:" << kol;
	cin >> i;
	return 0;
}
#endif