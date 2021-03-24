#pragma once

#include <memory>

class UnionFind
{
public:
    UnionFind(int size) :
        mData(nullptr),
        mSize(size)
    {
        mData = std::make_unique<int[]>(size);

        for (int i = 0; i < size; i++)
        {
            mData[i] = i;
        }
    }

    void Union(int x, int y)
    {
        x = Find(x);
        y = Find(y);

        if (x < y)
            mData[y] = x;
        else
            mData[x] = y;
    }

    int Find(int x)
    {
        while (mData[x] != x)
        {
            x = mData[x];
        }

        return x;
    }

private:
    std::unique_ptr<int[]> mData;
    int mSize;
};
