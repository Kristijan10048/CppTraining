#ifdef NOT_FIXED

#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

struct report
{
	int brnazb, posinp, redbr;

};

report tempr;
bool opendat(fstream& f1);
bool opendat(fstream& f1)
{
	char path[100];
	cout << "Vnesete ja patekata:";
	cin >> path;
	f1.open(path);
	if( !f1 )
	{
		cout << "\nGeska";
		return(false);
	}
	else
		return(true);
}

void getreport(fstream& fp, string zb);
void getreport(fstream& fp, string zb)
{
	char buf;
	bool sw = true;
	int posf = 0, pom = 0, lines = 0;
	while( !fp.eof() )
	{
		if( sw == true )
		{
			fp >> buf >> pom;
			if( buf == zb[0] )
			{
				tempr.brnazb = pom;
				tempr.posinp = lines;
				lines++;
			}
			sw = false;
		}
		if( sw == false )
		{
			while( buf != '\n' )
			{
				fp >> buf;
			}
			if( buf == '\n' )
				lines++;
		}
		if( buf == '\n' )
		{
			posf = 0;
			lines++;
		}
	}
}

void vnesizbor(fstream& f1)
{
	char buf;
	string pzbor, zbor;
	int curl = 0;
	cout << "Vneste go zborot sto sakate da go zapisete:";
	cin >> zbor;
	zbor[0] = toupper(zbor[0]);
	getreport(f1, zbor);
	while( tempr.posinp + 1 != curl )
	{
		f1 >> buf;
		if( buf == '\n' )
		{
			curl++;
		}
	}
	f1.seekg(
		f1 << zbor;
	f1.close();
}
int main()
{
	fstream f;
	opendat(f);
	vnesizbor(f);
	return 0;
}
//---------------------------------------------------------------------------
#endif