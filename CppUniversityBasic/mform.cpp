#ifdef NOT_FIXED
#include <iostream>
#include <conio.h>
#include <stdlib.h>

class forma
{
protected:
	int m;
public:
	forma()
	{
		m = 0;
	}
	forma(int a1)
	{
		m = a1;
	}
	virtual void prikazi();
};

void forma::prikazi()
{
	for( int j = 1; j <= m; j++ )
	{
		printf("\t");
		for( int i = 1; i < m; i++ )
		{
			textcolor(10);
			cprintf("X");
		}
		cprintf("\n\r");
	}
}

class forma1 :public forma
{
public:
	forma1()
	{
		m = 0;
	}
	forma1(int a1)
	{
		m = a1;
	}
	void prikazi()
	{
		for( int i = 1; i < m; i++ )
		{
			textcolor(13);
			cprintf("010");
		}
	}
};

class formab :public forma
{
public:
	formab()
	{
		m = 0;
	}
	formab(int a1)
	{
		m = a1;
	}
	void prikazi()
	{
		for( int j = 1; j <= m; j++ )
		{
			cprintf("\n\r");
			for( int i = 1; i < m; i++ )
			{
				textcolor(12);
				cprintf("|");
			}
		}
	}
};

forma1 f1l[20];
formab fbl[20];
void forma1lista();
void forma1lista(int& dol)
{

}
int main(int argc, char* argv[])
{
	forma f(10);
	forma1 f1(10);
	formab fb(5);
	f.prikazi();
	f1.prikazi();
	fb.prikazi();
	fb.prikazi();
	system("pause");

	return 0;
}
#endif