#pragma once

template <typename Item, typename Operation, Item DEFAULT>
class SegmentTree
{
private:
    Item* mData;
    unsigned int mSize;
    unsigned int mCount;

public:
    SegmentTree(unsigned int length) :
        mData(nullptr), mSize(1), mCount(0)
    {
        while (mSize < length)
            mSize = mSize << 1;

        mData = new Item[2 * mSize];

        for (int i = 0; i < 2 * mSize; i++)
            mData[i] = DEFAULT;
    }
    ~SegmentTree()
    {
        delete[] mData;
    }

    void Push(const Item& item)
    {
        if (mCount == mSize)
            return;

        mData[mSize + mCount] = item;

        Update((mSize + mCount) / 2);

        mCount++;
    }

    Item GetSegment(int left, int right)
    {
        if (left < 0 || right >= mSize)
            return Item();

        return GetSegment(left, right, 0, mSize - 1, 1);
    }

private:
    Item GetSegment(int left, int right, int start, int end, int index)
    {
        if (left > end || right < start)
            return DEFAULT;

        if (left <= start && end <= right)
            return mData[index];

        int mid = (start + end) / 2;

        return Operation()(
            GetSegment(left, right, start, mid, index * 2),
            GetSegment(left, right, mid + 1, end, index * 2 + 1));
    }

    void Update(int index)
    {
        if (index == 0) return;

        mData[index] = Operation()(mData[2 * index], mData[2 * index + 1]);

        Update(index / 2);
    }
};