#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int main()
{
    int lessonCount, teacherCount, subjectCount, tID, dID;
	
	//input 											TeacherId, DayId
    cin >> lessonCount >> teacherCount >> subjectCount >> tID >> dID;
    
	//vector of vectors
	vector< vector<pair<int,int>> > lessons(teacherCount);
    
	for(int i=0; i<lessonCount; ++i)
    {
        pair<int,int> tmp;
        
		int index;
        int junk;
		
		//TeacherId,  SubjectId, DayId, TimeSlot
        cin >> index >> junk >> tmp.first >> tmp.second;
		
		
        lessons[index-1].push_back(tmp);
		
		//Sorts the elements in the range [first,last) into ascending order.
        sort(lessons[index-1].begin(), lessons[index-1].end() );
    }
    int sub=-1;
    for(int i=0; i<teacherCount; ++i)
    {
        bool flag=true;
        for(pair<int,int> x : lessons[i])
        {
            for(pair<int,int> y: lessons[tID-1])
            {
                if(x == y)
                {
                    flag=false;
                }
            }
        }
        if(flag)
        {
            sub=i+1;
            i=teacherCount+1;
        }
    }
	
    cout<<sub;

    return 0;
}
