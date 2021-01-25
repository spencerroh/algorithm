#pragma once


template <typename T>
int LowerBound(const T* sortedArray, int length, const T& value)
{
	// value <= ?
	if (sortedArray[length - 1] < value)
		return length;

	int s = 0;
	int e = length;

	while (e - s > 0) {
		int m = (s + e) / 2;

		if (sortedArray[m] < value)
			s = m + 1;
		else
			e = m;
	}

	return e;
}

template <typename T>
int UpperBound(const T* sortedArray, int length, const T& value)
{
	// value <
	int s = 0;
	int e = length;

	while (e - s > 0) {
		int m = (s + e) / 2;

		if (sortedArray[m] <= value)
			s = m + 1;
		else
			e = m;
	}
	return e + 1;
}