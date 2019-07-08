#include <iostream>


using namespace std;

//node for binary bst search tree
class Node
{
	private:
	
	public:
		//public data members
		//Node* Root;
		Node* LeftNode;
		Node* RightNode;
		int Data;
		
		//constructors
		Node(int data)
		{
			this->Data = data;
			this->LeftNode = 0;
			this->RightNode = 0;
		}
		
		// Node(int data, Node* leftNode)
		// {
			// this->Data = data;
			// this->LeftNode = leftNode;
			// this->RightNode = 0;
		// }
		
		// Node(int data, Node* rightNode)
		// {
			// this->Data = data;
			// this->LeftNode = 0;
			// this->RightNode = rightNode;
		// }
		
		Node(int data, Node* leftNode, Node* rightNode)
		{
			this->Data = data;
			this->LeftNode = leftNode;
			this->RightNode = rightNode;
		}

};


//My binary search tree bst tree implementation
class MyBinaryTree
{
	private:
		//recurse insert in bynary search tree
		void Insert(int data, Node* parent)
		{
			// go to left
			if(data < (int)parent->Data)
			{
				//check if parent(rood) node has left child
				//if null then create left node
				if(!parent->LeftNode)			
					parent->LeftNode = new Node(data);
				else
					//recurse call: go to left subnode
					Insert(data, parent->LeftNode);
			}
			//go to right
			else
			{
				if(!parent->RightNode)
					parent->RightNode = new Node(data);
				else
					Insert(data, parent->RightNode);
			}
		}
		
		//recurse print of a binary search tree bst
		void PrintMe(Node* parent)
		{
			if(!parent)
				return;
			
			printf("Parent: %d", parent->Data);
			
			if(parent->LeftNode)
			{
				printf(" Left node %d", parent->LeftNode->Data);
			}
			
			if(parent->RightNode)
			{
				printf(" Right node %d", parent->RightNode->Data);
			}
			printf("\n");
			
			PrintMe(parent->LeftNode);
			PrintMe(parent->RightNode);
		}
	
	public:
		Node* Root = 0;
	
		//inserts element in to the three
		void Insert(int data)
		{
			if(!Root)
				Root = new Node(data);
			else		
				Insert(data, Root);
		}
		
		void PrintMe()
		{
			printf("Printing BST tree\n");
			PrintMe(Root);
		}
};

int main()
{
	MyBinaryTree myBst;
	int tmpArr[] = {10, 2 ,3 ,4, 5, 9,11};
	
	//insert elements in to BST
	for(auto i : tmpArr)
	{
		
		myBst.Insert(i);
		printf("Inserted element %d \n",i);
	}
	
	printf("Done inserting\n");
	
	//print the BST
	myBst.PrintMe();
	
	return 0;
}