#include <iostream>
#include <vector>
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

void cacheErase(Node*	pErased, std::vector<Node*>& cache) {

	if (pErased->pRight != nullptr)
		cacheErase(pErased->pRight, cache);
	if (pErased->pLeft != nullptr)
		cacheErase(pErased->pLeft, cache);
	
	auto it = std::find(cache.begin(), cache.end(), pErased);
	if(it != cache.end())
		cache.erase(it);
			
}

int BranchWithLargestSumOfNodes(Node* pRoot, std::vector<Node*>& cache) {
	cache.push_back(pRoot);
	int sum = pRoot->i;
	if (pRoot->pLeft != nullptr && pRoot->pRight != nullptr) {
		int l = BranchWithLargestSumOfNodes(pRoot->pLeft, cache);
		int r = BranchWithLargestSumOfNodes(pRoot->pRight, cache);
		sum += l > r ? l : r;
		l > r ? cacheErase(pRoot->pRight, cache) : cacheErase(pRoot->pLeft, cache);
	}
	else if (pRoot->pLeft != nullptr)
		sum += BranchWithLargestSumOfNodes(pRoot->pLeft, cache);
	else if (pRoot->pRight != nullptr)
		sum += BranchWithLargestSumOfNodes(pRoot->pRight, cache);
	return sum;
}

void printTheLargestBranch(Node* pRoot, std::vector<Node*> cache) {
	int sum = BranchWithLargestSumOfNodes(pRoot, cache);
	std::cout << "Branch with the largest sum is : ";
	for (int j = 0; j < cache.size(); j++)
		std::cout << cache.at(j)->i << " ";
	std::cout << "-> SUM = " << sum;
}

void main()
{	
	srand(time(NULL));
	std::vector<Node*> nodes;

	//TRIAL LOL
	Node* pRoot = nullptr;
	Node* p1 = new Node(9);
	Node* p2 = new Node(10);
	Node* p9 = new Node(10);
	Node* p10 = new Node(10);
	Node* p11 = new Node(10);
	Node* p12 = new Node(10);
	Node* p14 = new Node(10);
	Node* p13 = new Node(10);
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
	InsertToTree(pRoot, p10);
	InsertToTree(pRoot, p9);
	InsertToTree(pRoot, p11);
	InsertToTree(pRoot, p12);
	InsertToTree(pRoot, p13);
	InsertToTree(pRoot, p7);
	InsertToTree(pRoot, p8);
	PrintTree(pRoot,0);
	printTheLargestBranch(pRoot, nodes);
}