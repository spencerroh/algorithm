#pragma once
#include "Heap.h"

struct DijkstraDistance
{
	int index;
	int distance;
};

struct DijkstraResult
{
	int distance;
	int previousNodeIndex;
};

class DijkstraComparer
{
public:
	bool operator()(const DijkstraDistance& lhs, const DijkstraDistance& rhs) const
	{
		return lhs.distance < rhs.distance;
	}
};

#define I(s, d, c) (c * s + d)

DijkstraResult* DijkstraSearch(int nodeCount, int* map, int startIndex)
{
	DijkstraResult* result = new DijkstraResult[nodeCount];
	Heap<DijkstraDistance, DijkstraComparer> D;
	bool* visited = new bool[nodeCount];

	for (int i = 0; i < nodeCount; i++)
	{
		result[i].distance = (startIndex == i) ? 0 : 0x7FFFFFFF;
		result[i].previousNodeIndex = -1;

		visited[i] = false;
	}

	D.Push({
		startIndex,
		result[startIndex].distance
	});

	while (!D.Empty())
	{
		DijkstraDistance r;
		D.Pop(r);

		if (visited[r.index])
			continue;

		for (int i = 0; i < nodeCount; i++)
		{
			if (r.index == i)
				continue;

			const int distance = map[I(r.index, i, nodeCount)];

			if (distance == -1)
				continue;

			if (r.distance + distance < result[i].distance)
			{
				result[i].distance = r.distance + distance;
				result[i].previousNodeIndex = r.index;

				D.Push({
					i,
					result[i].distance
				});
			}
		}

		visited[r.index] = true;
	}

	delete[] visited;

	return result;
}
