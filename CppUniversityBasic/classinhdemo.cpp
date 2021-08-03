#ifdef NOT_FIXED
#include <iostream.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

class Base
{
protected:
	int test;
public:
	void nonv()
	{
		cout << "nonvirtual" << endl;
	}
	virtual void message1()
	{
		cout << "Base - message1\n";
	}
	virtual void message2()
	{
		cout << "Base - message2\n";
	}
	void message3()
	{
		cout << "Base - message3\n";
	}

};

class Derived :Base
{
public:
	virtual void message1()
	{
		cout << "Derived - message1\n";
	}
	void message2(int);
	void message3()
	{
		cout << "Derived - message3\n";
	}
	virtual void tests()
	{
		cout << "test=" << test << endl;
	}
};



void Derived::message2(int x)
{
	int y;
	x = y;
	cout << "y=" << y << endl;
}



main()
{
	clrscr();
	Base a;
	Derived* dp, B, q1;
	Base A, * bp = &B;
	bp->message1();
	bp->message2();
	bp->message3();
	bp = &A;
	bp->message1();// se izvrsuva Base::message1()
	a.message1();
	a.message2();
	a.message3();
	q1.message1();
	q1.message2(1);
	q1.message3();
	q1.message1();
	q1.message2(21);
	q1.message3();
	q1.tests();
	bp = &a;
	bp->nonv();
	bp->message1();
	bp = &q1;
	bp->message1();
	system("pause");
}
#endif