#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Algorithm/Sort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UniqueTests)
	{
	public:

		TEST_METHOD(UniqueTestWithNormalCase)
		{
			int unique[] = {
				1, 1, 3, 4, 4, 4, 5, 6, 7, 7, 8, 9, 9
			};

			int u = Unique<int>(unique, sizeof(unique) / sizeof(unique[0]));

			Assert::AreEqual(8, u);
			Assert::AreEqual(1, unique[0]);
			Assert::AreEqual(3, unique[1]);
			Assert::AreEqual(4, unique[2]);
			Assert::AreEqual(5, unique[3]);
			Assert::AreEqual(6, unique[4]);
			Assert::AreEqual(7, unique[5]);
			Assert::AreEqual(8, unique[6]);
			Assert::AreEqual(9, unique[7]);
		}
		TEST_METHOD(UniqueTestWithSingleItem)
		{
			int unique[] = {
				1
			};

			int u = Unique<int>(unique, sizeof(unique) / sizeof(unique[0]));

			Assert::AreEqual(1, u);
			Assert::AreEqual(1, unique[0]);
		}

		TEST_METHOD(UniqueTestWithAllSameItems)
		{
			int unique[] = {
				1, 1, 1, 1, 1
			};

			int u = Unique<int>(unique, sizeof(unique) / sizeof(unique[0]));

			Assert::AreEqual(1, u);
			Assert::AreEqual(1, unique[0]);
		}
	};
}