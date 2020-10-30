#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Algorithm/DijkstraSearch.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(DijkstraTest)
	{
	public:

		TEST_METHOD(DijkstraSearchTest1)
		{
			int map[6][6] = { 0 };
			memset(map, -1, sizeof(map));

			map[0][1] = 10;
			map[0][2] = 30;
			map[0][3] = 15;
			map[1][4] = 20;
			map[2][5] = 5;
			map[3][2] = 5;
			map[3][5] = 20;
			map[4][5] = 20;
			map[5][4] = 20;


			DijkstraResult* result = DijkstraSearch(6, (int*)map, 0);

			Assert::AreEqual(0, result[0].distance);
			Assert::AreEqual(-1, result[0].previousNodeIndex);

			Assert::AreEqual(10, result[1].distance);
			Assert::AreEqual(0, result[1].previousNodeIndex);

			Assert::AreEqual(20, result[2].distance);
			Assert::AreEqual(3, result[2].previousNodeIndex);

			Assert::AreEqual(15, result[3].distance);
			Assert::AreEqual(0, result[3].previousNodeIndex);

			Assert::AreEqual(30, result[4].distance);
			Assert::AreEqual(1, result[4].previousNodeIndex);

			Assert::AreEqual(25, result[5].distance);
			Assert::AreEqual(2, result[5].previousNodeIndex);

			delete[]result;
		}

		TEST_METHOD(DijkstraSearchTest2)
		{
			int map[5][5] = { 0 };
			memset(map, -1, sizeof(map));

			map[0][1] = 12;
			map[1][0] = 12;
			map[0][2] = 10;
			map[2][0] = 10;
			map[0][3] = 5;
			map[3][0] = 5;
			map[1][3] = 13;
			map[3][1] = 13;
			map[1][4] = 2;
			map[4][1] = 2;
			map[2][4] = 3;
			map[4][2] = 3;
			map[3][4] = 1;
			map[4][3] = 1;

			DijkstraResult* result = DijkstraSearch(5, (int*)map, 0);

			Assert::AreEqual(0, result[0].distance);
			Assert::AreEqual(-1, result[0].previousNodeIndex);

			Assert::AreEqual(8, result[1].distance);
			Assert::AreEqual(4, result[1].previousNodeIndex);

			Assert::AreEqual(9, result[2].distance);
			Assert::AreEqual(4, result[2].previousNodeIndex);

			Assert::AreEqual(5, result[3].distance);
			Assert::AreEqual(0, result[3].previousNodeIndex);

			Assert::AreEqual(6, result[4].distance);
			Assert::AreEqual(3, result[4].previousNodeIndex);

			delete [] result;

		}
	};
}