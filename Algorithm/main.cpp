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

#include <functional>
#include "algorithm.h" 
#include "BinaryTree.h"


int main() 
{
	BinaryTree<int, int, std::less<int>> tree;

	tree.Add(5, 5);
	tree.Add(3, 3);
	tree.Add(8, 8);
	tree.Add(1, 1);
	tree.Add(4, 4);
	tree.Add(6, 6);
	tree.Add(9, 9);
	tree.Add(10, 10);

	auto count = tree.GetCount();
	auto depth = tree.GetDepth();

	tree.Remove(8);
	tree.Remove(6);
	tree.Remove(4);
	tree.Remove(3);

	

	return 0;
}