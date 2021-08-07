#include <string>
#include <iostream>
using namespace std;

int main()
{
	char str1[] = "Sample string";
	char mail[] = "mail to:";
	char str2[100];
	char str3[100];
	strcpy(str2, str1);
	strcat(str2, mail);
	printf("str2: %s\n", str2);
	strcpy(str3, "copy successful");
	printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);
	system("pause");
	return 0;

}
