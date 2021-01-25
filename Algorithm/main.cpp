#include <stdio.h>

/*
	���� Ǯ�Ⱑ ���۵Ǹ� �ٷ� �ڵ����� ����, �ּ� 30���� ������ ����(������ �����Ѱ�, �������� ��)�� 
	�����Ͽ� ���� �� �����ϴ� �������� �����Ѵ�.

	Tree�� ���̰� 5000�����̸� DFS ���� ���� Ư���� ū �ڷ����� ���ٸ� ���� �����ϴ�.

	BFS Ž���� �ִܰŸ� ������ �����ϸ� ����� �ʿ䰡 ����.


	1. Hash + Bucket(or Trie)
	2. Heap (Priority Queue)
	3. Linked List
	4. Graph
	5. DFS/BFS
	6. Sort - Quick Sort, Merge Sort

	�ڷᱸ��
	- Vector
	- Linked List
	- Trie
	- Hash Table(Open Address, Direct Address)
	- Queue
	- Stack
	- Priority Queue

	KMP
	���ͽ�Ʈ��
	�����̵�-����?


	Binary Tree
	Hash Table(OA, DA, Bucket ���)
	Linked List
	Double Linked List
	Heap
	Queue
	Stack
	Vector


	Hash Algorithm (djc2)

*/

#include <iostream>
#include <functional>
#include "algorithm.h" 
#include "BinaryTree.h"

using namespace std;

int main() 
{
	int unique[] = {
		1, 1, 3, 4, 4, 4, 5, 6, 7, 7, 8, 9, 9
	};

	int u = Unique<int>(unique, sizeof(unique) / sizeof(unique[0]));
	
	BinaryTree<int, int, std::less<int>> tree;

	for (int i = 0; i < 10; i++)
		tree.Add(i, i);



	int key = 0;
	int next = 0;

	for (int i = 0; i < 10; i++)
	{
		if (tree.Next(i, next))
			cout << "next of " << i << " is " << next << endl;
		else
			cout << "next of " << i << " is nothing." << endl;
	}

	

	return 0;
}