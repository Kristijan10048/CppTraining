#include "pch.h"
#include<iostream>
#include<string>

using namespace std;

#if 1
void dbg(string arg) { cout << "dbg:" << arg << endl; }
#endif



class Node
{
public:
	Node* m_next;
	int m_data;

	//constructors
	Node()
	{
		this->m_data = 0;
		this->m_next = 0;
	}

	Node(int dataPtr)
	{
		this->m_data = dataPtr;
		this->m_next = 0;
	}

	Node(int data, Node* next)
	{
		this->m_data = data;
		this->m_next = next;
	}

	int GetData() { return m_data; }
};

class MyList
{
private:
	Node * m_first = 0;
	Node * m_last = 0;

public:
	//Getter methods
	Node* GetFirst() { return this->m_first; }
	Node* GetLast() { return this->m_last; }

	//insert elements at the end of the list
	void InsertAtEnd(int data)
	{
		dbg("Insert:" + std::to_string(data));

		//inset the first element
		if (!this->m_first)
		{
			//
			this->m_first = new Node(data);

			//set last to point to first
			this->m_last = this->m_first;
		}
		else
		{
			//create new node for last.next
			this->m_last->m_next = new Node(data);

			//shift last to last.next
			this->m_last = this->m_last->m_next;
		}
	}

	//prints content of the Linked list
	void PrintMe()
	{
		if (!this->m_first)
			return;

		Node * current = this->m_first;

		dbg("First :" + std::to_string(current->GetData()));

		while (current)
		{
			dbg("Value :" + current->m_data);
			current = current->m_next;
		}
	}
};



int main()
{
	MyList ml;
	Node* t = new Node();

	if (t)
		dbg("Not Null");


	for (int i = 0; i < 10; i++)
		ml.InsertAtEnd(i);

	dbg("Insertion finished");

	ml.PrintMe();
	cout << "Print finished" << endl;

	return 0;
}