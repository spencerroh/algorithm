#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Algorithm/Search.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(SearchTests)
	{
	public:

		TEST_METHOD(LowerBoundTestWithNormalCase)
		{
			// value <= ?
			int items[] = {
				1, 3, 5, 7, 9, 11, 13, 15, 17, 19
			};

			Assert::AreEqual(0, LowerBound(items, sizeof(items) / sizeof(items[0]), 0));
			Assert::AreEqual(2, LowerBound(items, sizeof(items) / sizeof(items[0]), 4));
			Assert::AreEqual(4, LowerBound(items, sizeof(items) / sizeof(items[0]), 9));
			Assert::AreEqual(9, LowerBound(items, sizeof(items) / sizeof(items[0]), 19));
		}

		TEST_METHOD(UpperBoundTestWithNormalCase)
		{
			// value < ?
			int items[] = {
				1, 3, 5, 7, 9, 11, 13, 15, 17, 19
			};

			Assert::AreEqual(0, LowerBound(items, sizeof(items) / sizeof(items[0]), 0));
			Assert::AreEqual(2, UpperBound(items, sizeof(items) / sizeof(items[0]), 4));
			Assert::AreEqual(5, UpperBound(items, sizeof(items) / sizeof(items[0]), 9));
			Assert::AreEqual(10, UpperBound(items, sizeof(items) / sizeof(items[0]), 20));
		}
	};
}