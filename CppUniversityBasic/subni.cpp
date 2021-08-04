#ifdef NOT_FIXED
#include <iostream>
#include<conio.h>
#include<stdlib.h>


int main(int argc, char* argv[])
{
	int a[20], i, n, pomn[20], pdolz, subn[20], sbdol;
	cout << "Kolku elementi ima nizata:";
	cin >> n;
	for( i = 0; i <= n - 1; i++ )
	{
		cout << "A[" << i << "]=";
		cin >> a[i];
		cout << "\n\r";
	}
	i = 0;
	int j = 0, z;
	sbdol = 0;
	bool prev;
	i = 0;
	while( i != n - 1 )
	{
		if( a[i] < a[i + 1] )
		{
			pomn[j] = a[i];
			j++;
			i++;
		}
		else
			(j > sbdol)
		{
			pomn[j] = a[k]
				for( int k = 0; k <= j; k++ )
					subn[k] = pomn[k];
			sbdol = j + 1;
		}
	}

	for( i = 0; i <= sbdol - 1; i++ )
		cout << subn[i] << ", ";
	system("pause");
	return 0;
}
#endif