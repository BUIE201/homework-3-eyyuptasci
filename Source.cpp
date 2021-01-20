#include <iostream>
#include <vector>
#include <stdlib.h> 
#include <time.h>

struct Node;
void InsertToTree(Node*& pRoot, Node* pNew);

struct Node
{
public:
	int i;
	Node* pLeft;
	Node* pRight;

	Node(int iIn, Node*& pRoot) : i(iIn), pLeft(nullptr), pRight(nullptr) {
		InsertToTree(pRoot, this);
	}
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

void cacheErase(Node* pErased, std::vector<Node*>& cache) {

	if (pErased->pRight != nullptr)
		cacheErase(pErased->pRight, cache);
	if (pErased->pLeft != nullptr)
		cacheErase(pErased->pLeft, cache);
	
	auto it = std::find(cache.begin(), cache.end(), pErased);
	if(it != cache.end())
		cache.erase(it);
			
}

int BranchWithLargestSumOfNodes(Node* pRoot, std::vector<Node*>& cache) {
	//This function returns the largest sum of nodes. In the cache vector it holds the nodes that generates that sum.
	if (pRoot == nullptr)
		return 0;
	cache.push_back(pRoot);
	int sum = pRoot->i;
	if (pRoot->pLeft != nullptr && pRoot->pRight != nullptr) {
		int l = BranchWithLargestSumOfNodes(pRoot->pLeft, cache);
		int r = BranchWithLargestSumOfNodes(pRoot->pRight, cache);
		sum += l > r ? l : r;
		//The nodes that generates the less sum are deleted from the cache.
		l > r ? cacheErase(pRoot->pRight, cache) : cacheErase(pRoot->pLeft, cache);
	}
	else if (pRoot->pLeft != nullptr)
		sum += BranchWithLargestSumOfNodes(pRoot->pLeft, cache);
	else if (pRoot->pRight != nullptr)
		sum += BranchWithLargestSumOfNodes(pRoot->pRight, cache);
	return sum;
}

void printTheLargestBranch(Node* pRoot) {
	std::vector<Node*> cache;
	int sum = BranchWithLargestSumOfNodes(pRoot, cache);
	std::cout << "Branch with the largest sum is : ";
	for (int j = 0; j < cache.size(); j++)
		std::cout << cache.at(j)->i << " ";
	std::cout << "-> SUM = " << sum;
}

void main()
{	
	srand(time(NULL)); //I made insertion random since ATÜ removed sorted property.


	//TRIAL
	Node* pRoot = nullptr;
	for (int i = 1; i < 40; i++) {
		new Node(i,pRoot);
	}

	PrintTree(pRoot,0); // To see what is the tree.
	printTheLargestBranch(pRoot);
}