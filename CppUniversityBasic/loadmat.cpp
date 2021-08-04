#ifdef NOT_FIXED

#include <vcl.h>
#include <iostream.h>
#include <conio.h>
#include <fstream.h>

int matrix[30][3], kol, red;
void loadmatrix()
{
	char path[100], zn;
	ifstream f;
	int i = 0, j = 0, br;
	cout << "Vnesete ja patekata:";
	cin >> path;
	f.open(path);
	while( !f.eof() )
	{
		f >> matrix[i][j];
		j++;
		if( j >= 3 )
		{
			j = 0;
			i++;
		}
	}
	kol = i;
	red = 3;
}
void printmatrix()
{
	int i, j;
	for( i = 0; i <= kol - 1; i++ )
	{
		for( j = 0; j <= red - 1; j++ )
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}
int main(int argc, char* argv[])
{
	loadmatrix();
	printmatrix();
	system("pause");
	return 0;
}
#endif