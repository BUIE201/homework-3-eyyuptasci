#include <iostream>
#include <stdlib.h> 
#include <time.h>
struct Node
{
	int i;
	Node* pLeft;
	Node* pRight;

	Node(int iIn) : i(iIn), pLeft(nullptr), pRight(nullptr) {}
};

void InsertToTree(Node*& pRoot, Node* pNew)
{
	
	if (!pRoot)
	{
		pRoot = pNew;
		return;
	}
	

	if (rand() % 2) {
		InsertToTree(pRoot->pLeft, pNew);
		
	}
		
	else
		InsertToTree(pRoot->pRight, pNew);
}

void PrintTree(Node* pRoot, int Level)
{
	if (!pRoot)
		return;

	PrintTree(pRoot->pRight, Level + 1);

	for (int i = 0; i < Level; i++)
		std::cout << "  ";
	std::cout << pRoot->i << std::endl;

	PrintTree(pRoot->pLeft, Level + 1);
}

int BranchWithLargestSumOfNodes(Node* pRoot) {
	int sum = pRoot->i;
	if (pRoot->pLeft != nullptr && pRoot->pRight != nullptr)
		sum += BranchWithLargestSumOfNodes(pRoot->pLeft) > BranchWithLargestSumOfNodes(pRoot->pRight) ? BranchWithLargestSumOfNodes(pRoot->pLeft) : BranchWithLargestSumOfNodes(pRoot->pRight);
	else if (pRoot->pLeft != nullptr)
		sum += BranchWithLargestSumOfNodes(pRoot->pLeft);
	else if (pRoot->pRight != nullptr)
		sum += BranchWithLargestSumOfNodes(pRoot->pRight);
	return sum;
}

void main()
{	
	srand(time(NULL));
	int i;

	Node* pRoot = nullptr;
	Node* p1 = new Node(9);
	Node* p2 = new Node(10);
	Node* p3 = new Node(8);
	Node* p4 = new Node(5);
	Node* p5 = new Node(6);
	Node* p6 = new Node(7);
	Node* p7 = new Node(11);
	Node* p8 = new Node(12);
	InsertToTree(pRoot, p1);
	InsertToTree(pRoot, p2);
	InsertToTree(pRoot, p3);
	InsertToTree(pRoot, p4);
	InsertToTree(pRoot, p5);
	InsertToTree(pRoot, p6);
	InsertToTree(pRoot, p7);
	InsertToTree(pRoot, p8);
	PrintTree(pRoot,0);
	std::cout << BranchWithLargestSumOfNodes(pRoot);
}