#include "pch.h"
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;
int Scheduler()
{
	int lessonCount, teacherCount, subjectCount, tID, dID;

	//input 											TeacherId, DayId
	cin >> lessonCount >> teacherCount >> subjectCount >> tID >> dID;

	//vector of vectors
	vector< vector<pair<int, int>> > lessons(teacherCount);

	for (int i = 0; i < lessonCount; ++i)
	{
		pair<int, int> tmp;

		int index;
		int junk;

		//TeacherId,  SubjectId, DayId, TimeSlot
		cin >> index >> junk >> tmp.first >> tmp.second;


		lessons[index - 1].push_back(tmp);

		//Sorts the elements in the range [first,last) into ascending order.
		sort(lessons[index - 1].begin(), lessons[index - 1].end());
	}
	int sub = -1;
	for (int i = 0; i < teacherCount; ++i)
	{
		bool flag = true;
		for (pair<int, int> x : lessons[i])
		{
			for (pair<int, int> y : lessons[tID - 1])
			{
				if (x == y)
				{
					flag = false;
				}
			}
		}
		if (flag)
		{
			//increate substitute teacher Id
			sub = i + 1;
			i = teacherCount + 1;
		}
	}

	cout << sub;

	return 0;
}



int main()
{
	Scheduler();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
