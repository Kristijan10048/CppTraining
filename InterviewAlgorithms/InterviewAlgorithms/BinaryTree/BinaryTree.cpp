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
	
		// 	1. Traverse the left subtree, i.e., call Inorder(left-subtree)
		// 	2. Visit the root.
		// 	3. Traverse the right subtree, i.e., call Inorder(right-subtree)
		void InOrder(Node* parent)
		{
			if(!parent)
				return;
			
			
			//if(!)
			InOrder(parent->LeftNode);
			
			printf("Node : %d\n", parent->Data);
			
			InOrder(parent->RightNode);
		}
		
		void PreOrder(Node* parent)
		{
			if(!parent)
				return;
			
			printf("Node : %d\n", parent->Data);
			
			InOrder(parent->LeftNode);		
			
			InOrder(parent->RightNode);
		}
		
		void PostOrder(Node* parent)
		{
			if(!parent)
				return;
			
			InOrder(parent->LeftNode);		
			
			InOrder(parent->RightNode);
			
			printf("Node : %d\n", parent->Data);
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
		
		// Depth First Traversals:
		// Inorder (Left, Root, Right)
		// 	1. Traverse the left subtree, i.e., call Inorder(left-subtree)
		// 	2. Visit the root.
		// 	3. Traverse the right subtree, i.e., call Inorder(right-subtree)
		// Preorder (Root, Left, Right)
		// 	1. Visit the root.
		// 	2. Traverse the left subtree, i.e., call Preorder(left-subtree)
		// 	3. Traverse the right subtree, i.e., call Preorder(right-subtree) 
		// Postorder (Left, Right, Root)
		// 	1. Traverse the left subtree, i.e., call Postorder(left-subtree)
		// 	2. Traverse the right subtree, i.e., call Postorder(right-subtree)
		// 	3. Visit the root.
		
		//travers the tree in oreder
		void InOrder()
		{
			InOrder(this->Root);
		}
		
		//travers the tree in pre order
		void PreOrder()
		{
			PreOrder(this->Root);
		}
		
		//travers the tree in post order
		void PostOrder()
		{
			PostOrder(this->Root);
		}
		
		//prints the tree
		void PrintMe()
		{
			printf("Printing BST tree\n");
			PrintMe(Root);
		}
};

//tests implementation of the class MyBinaryTree
void TreeImplementationTest()
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
	
	printf("In order print:\n");
}

//tests the implementation of InOrder, PreOrder and PostOrder
void TreeTraversImplementation()
{
	MyBinaryTree bst;
	int elements[] = {11, 9, 7, 5, 3, 1, 2, 4, 6, 8, 10, 17, 19, 20, 16, 18};
	
	for(auto i : elements)
		bst.Insert(i);
	
	printf("Done inserting\n");
	printf("Tree content\n");
	
	//prints the content of the tree
	bst.PrintMe();
	
	printf("-------------------------\n");
	printf("In order :\n");
	bst.InOrder();
	
	printf("-------------------------\n");
	printf("Pre order :\n");
	bst.PreOrder();
	
	printf("-------------------------\n");
	printf("Post order :\n");
	bst.PostOrder();
}

int main()
{
	TreeTraversImplementation();
		
	return 0;
}