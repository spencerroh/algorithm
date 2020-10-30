#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Algorithm\Heap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	struct LessThan
	{
		bool operator()(int i, int j)
		{
			return i < j;
		}
	};

	struct GreaterThan
	{
		bool operator()(int i, int j)
		{
			return i > j;
		}
	};

	TEST_CLASS(HeapTest)
	{
	public:
		
		TEST_METHOD(GreaterThanTest)
		{
			Heap<int, GreaterThan> aaa;
			aaa.Push(10);
			aaa.Push(3);
			aaa.Push(50);
			aaa.Push(25);

			int i;

			aaa.Pop(i);
			Assert::AreEqual(50, i);

			aaa.Pop(i);
			Assert::AreEqual(25, i);
			
			aaa.Pop(i);
			Assert::AreEqual(10, i);

			aaa.Pop(i);
			Assert::AreEqual(3, i);
		}

		TEST_METHOD(LessThanTest)
		{
			Heap<int, LessThan> aaa;
			aaa.Push(10);
			aaa.Push(3);
			aaa.Push(50);
			aaa.Push(25);

			int i;

			aaa.Pop(i);
			Assert::AreEqual(3, i);

			aaa.Pop(i);
			Assert::AreEqual(10, i);

			aaa.Pop(i);
			Assert::AreEqual(25, i);

			aaa.Pop(i);
			Assert::AreEqual(50, i);
		}

	};
}