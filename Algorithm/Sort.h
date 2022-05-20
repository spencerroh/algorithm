#pragma once

template <class T, class Predict>
void MergeSort(T* arr, int s, int e, Predict p)
{
	if (s == e - 1)
		return;

	int m = (s + e) / 2;

	MergeSort(arr, s, m, p);
	MergeSort(arr, m, e, p);

	int i = s, j = m, x = 0;
	T* u = new T[e - s];

	while (i < m && j < e)
	{
		if (p(i, j)) u[x++] = arr[i++];
		else u[x++] = arr[j++];
	}

	while (i < m) u[x++] = arr[i++];
	while (j < e) u[x++] = arr[j++];

	for (int i = 0; i < e - s; i++)
		arr[s + i] = u[i];

	delete[] u;
}

template <class T>
int Unique(T* sortedArray, size_t length)
{
	T elem = sortedArray[0];

	int j = 1;
	for (size_t i = 1; i < length; i++)
	{
		if (elem != sortedArray[i])
		{
			elem = sortedArray[i];
			sortedArray[j++] = elem;
		}
	}

	return j;
}

template <class T>
int Swap(T& value1, T& value2)
{
	T temp = value1;
	value1 = value2;
	value2 = temp;
}

template <class T, class Predict>
void QuickSort(T* arr, int first, int last, Predict p)
{
	if (first >= last)
		return;

	int pivot = first;
	int left = first;
	int right = last;

	while (left < right)
	{
		while (arr[left] <= arr[pivot] && left < last)
			left++;

		while (arr[right] > arr[pivot])
			right--;

		if (left < right)
			Swap(arr[left], arr[right]);
	}

	Swap(arr[pivot], arr[right]);

	QuickSort(arr, first, right - 1);
	QuickSort(arr, right + 1, last);
}