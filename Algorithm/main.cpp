#include <stdio.h>

/*
	문제 풀기가 시작되면 바로 코딩하지 말고, 최소 30분은 문제의 내용(변수의 상하한값, 제약조건 등)을 
	정리하여 시작 시 제공하는 연습지에 정리한다.

	Tree의 깊이가 5000이하이면 DFS 로직 내에 특별히 큰 자료형이 없다면 적용 가능하다.

	BFS 탐색은 최단거리 문제를 제외하면 사용할 필요가 없다.


	1. Hash + Bucket(or Trie)
	2. Heap (Priority Queue)
	3. Linked List
	4. Graph
	5. DFS/BFS
	6. Sort - Quick Sort, Merge Sort

	자료구조
	- Vector
	- Linked List
	- Trie
	- Hash Table(Open Address, Direct Address)
	- Queue
	- Stack
	- Priority Queue

	KMP
	다익스트라
	프로이드-워샬?


	Binary Tree
	Hash Table(OA, DA, Bucket 방식)
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