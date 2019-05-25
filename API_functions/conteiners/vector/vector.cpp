#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

//calculates magnitude of the vector
//res = sqrt(x1^2 + x2^2 + x3^2+ ... + xn^2);
double Magnitude(std::vector<double> v)
{
	double res=0;
	
	for(int i=0; i<v.size(); i++)
		res += pow(v[i], 2);
	
	return sqrt(res);
}

void main()
{
	std::vector<int> v1 = {1, 2, 3, 4, 5, 6};
	
	//show the content of the vector
	for(int i = 0; i<v1.size(); i++)
		cout<< v1[i] <<", ";
	cout<<endl;
	
	//scalar multipication
	const int c_sacalar = 2;
	cout<< "Multiply vector with scalar:"<<endl;
	for(int i = 0; i<v1.size(); i++)
	{
		v1[i] = v1[i] * c_sacalar;
		cout<< v1[i] <<", ";
	}
	cout<<endl;
	
	//calculate dot product of two vectros
	std::vector<double> a = {1, 2, 3};
	std::vector<double> b = {4, -5, 6};
	//res = |a|*|b|*cos(theta)
	 //or a . b = x11 * x12 + y11 * y12 + z11 * z21
	double res = 0;
	
	for(int i = 0; i< a.size(); i++)
		res += a[i] * b[i];
	
	//a⋅b=1(4)+2(−5)+3(6)=4−10+18=12.
	cout << "Dot product of vectors a and b is :" << res<< endl;
}