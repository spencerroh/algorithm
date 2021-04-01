# 알고리즘

## 구현 예정
- Queue
- Stack
- Vector
- KMP
- Graph에서 Loop 찾기

## 자료구조
- Linked List
```cpp
template <class T>
List<T>* Add(List<T>** head, T value);

template <class T>
void Remove(List<T>** head, T value);

template <class T>
void Clear(List<T>** head);
```
- Binary Tree
  - Add/Remove/Find
  - Next
- Heap
  - Push, Pop
- Segment Tree
```cpp
struct MaxOperator {
public:
    int operator()(const int& a, const int& b)
    {
        return a < b ? b : a;
    }
};
SegmentTree<int, MaxOperator, 0> segmentTree(4);
segmentTree.Push(1);
segmentTree.Push(2);
segmentTree.Push(3);
segmentTree.Push(4);

int max = segmentTree.GetSegment(1, 2);
```
- Union-Find
```cpp
UnionFind union(4);
union.Union(0, 1);
union.Union(2, 3);

int g1 = union.Find(1); // 0
int g2 = union.Find(3); // 2

union.Union(0, 2);

int g3 = union.Find(3); // 0
```
  

## Data Manipulation
- Merge Sort
```cpp
template <class T, class Predict>
void MergeSort(T* arr, int s, int e, Predict p)
```
- Unique
```cpp
template <class T>
int Unique(T* sortedArray, size_t length)
```

## Search
- Dijkstra Search
```cpp
struct DijkstraResult
{
	int distance;
	int previousNodeIndex;
};

DijkstraResult* DijkstraSearch(int nodeCount, int* map, int startIndex)
```
- Parametric Search
```cpp
template <class Predict>
int ParametricSearch(int l, int r, Predict p)
```
- Lower/Upper Bound
```cpp
template <typename T>
int LowerBound(const T* sortedArray, int length, const T& value)

template <typename T>
int UpperBound(const T* sortedArray, int length, const T& value)
```

## Common
- Hash
  - djb2
- String Operation
  - length, copy, compare, clone
