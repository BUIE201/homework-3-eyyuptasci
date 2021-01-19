#include <iostream>
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

	if (pNew->i <= pRoot->i)
		InsertToTree(pRoot->pLeft, pNew);
	else
		InsertToTree(pRoot->pRight, pNew);
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
	int i;

	Node* pRoot = nullptr;
	Node* p1 = new Node(9);
	Node* p2 = new Node(10);
	Node* p3 = new Node(8);
	Node* p4 = new Node(5);
	Node* p5 = new Node(6);
	InsertToTree(pRoot, p1);
	InsertToTree(pRoot, p2);
	InsertToTree(pRoot, p3);
	InsertToTree(pRoot, p4);
	InsertToTree(pRoot, p5);
	std::cout << BranchWithLargestSumOfNodes(pRoot);
}