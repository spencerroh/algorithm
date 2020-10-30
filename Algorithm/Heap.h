#pragma once
template <class T, class Comparer>
class Heap
{
	/* Remark:
	이 구현체에서 mData는 1부터 시작하는 배열로 사용한다.
	즉, mData[0]은 사용하지 않는다.

	이렇게 구현해야 부모-자식간 Index 계산이 쉽다.

	임의의 i의 부모: i / 2
	임의의 i의 자식: i * 2, i * 2 + 1
	*/
public:
	void Push(const T& value)
	{
		if (mCount + 1 == mSize)
			Expand();

		mData[++mCount] = value;

		int i = mCount;
		while (i > 1 && mComparer(mData[i], mData[i / 2]))
		{
			int parent = i / 2;
			Swap(mData[i], mData[parent]);
			i = parent;
		}
	}

	bool Pop(T& value)
	{
		if (mCount == 0)
			return false;

		value = mData[1];
		mData[1] = mData[mCount--];

		int i = 1;
		while (i * 2 <= mCount)
		{
			int child = (i * 2 + 1 > mCount) ?
				i * 2 :
				mComparer(mData[i * 2], mData[i * 2 + 1]) ? i * 2 : i * 2 + 1;

			if (mComparer(mData[i], mData[child]))
				break;

			Swap(mData[i], mData[child]);

			i = child;
		}

		return true;
	}

	bool Empty() const
	{
		return mCount == 0;
	}

	Heap() : mSize(2), mCount(0) {
		mData = new T[mSize];
		mData[0] = T();
	}

private:
	void Expand() {
		mSize *= 2;

		T* newData = new T[mSize];
		for (int i = 0; i <= mCount; i++)
			newData[i] = mData[i];

		delete[] mData;

		mData = newData;
	}

	void Swap(T& lhs, T& rhs)
	{
		T temp = lhs;
		lhs = rhs;
		rhs = temp;
	}

private:
	int mSize, mCount;
	T* mData;
	Comparer mComparer;
};