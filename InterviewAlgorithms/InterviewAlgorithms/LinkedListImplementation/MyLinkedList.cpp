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

	//created new node with null pointer for next
	Node(int data)
	{
		this->m_data = data;
		this->m_next = 0;
	}

	//creates new node with pointer next pointing to next node
	Node(int data, Node* next)
	{
		this->m_data = data;
		this->m_next = next;
	}

	//returns the data from current node
	int GetData() { return m_data; }
};

//My cpp implementation of single connected list 
class MyList
{
private:
	Node * m_first = 0;
	Node * m_last = 0;

public:
	//Getter methods
	Node* GetFirst() { return this->m_first; }
	Node* GetLast() { return this->m_last; }

	//insert element at the end of the list
	void InsertAtEnd(int data)
	{
		dbg("Insert :" + std::to_string(data));

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

	//inset element at the begining of the list
	void InsertAtBeginning(int data)
	{
		if(!m_first)
		{
			dbg("no shft");
			this->m_first = new Node(data);
		}
		else
		{
			Node * tmpNext = this->m_first;
			
			this->m_first = new Node(data, tmpNext);
			//this->m_first->m_next = tmpNext;
		}
	}
	
	//prints content of the Linked list
	void PrintMe()
	{
		if (!this->m_first)
			return;

		Node * current = this->m_first;
		
		while (current)
		{
			dbg("Value :" + std::to_string(current->m_data));
			current = current->m_next;
		}
	}
};


int main()
{
	MyList ml;

	for (int i = 0; i < 10; i++)
		ml.InsertAtEnd(i);

	dbg("Insertion finished");

	ml.InsertAtBeginning(66);
	
	ml.PrintMe();
	dbg("Print finished");

	return 0;
}