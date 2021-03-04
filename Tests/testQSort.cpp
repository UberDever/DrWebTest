#include "pch.h"
#include "../DrWebTest/QSort.h"

// QSort tests for complete TDD
TEST(QSort, SortColumnOf4x4Matrix)
{
	int matrix[] = { 5, 8, 0, 4,
					 9, 1, 3, 8,
					 5, 6, 7, 3,
					 3, 9, 7, 2 };

	int colNum = 1;

	qsort_3way(matrix + colNum, 4, cmpAscending, 4);

	testing::internal::CaptureStdout();
	for (int i = 0; i < 16; i++)
	{
		printf("%d ", matrix[i]);
	}
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(output.c_str(), "5 1 0 4 " "9 6 3 8 " "5 8 7 3 " "3 9 7 2 ");
}
TEST(QSort, VeryLargeNumberWithRepetitions)
{
	int n = 100000;
	int repeatCount = 20;
	int* arr1 = new int[n];
	int* arr2 = new int[n];

	std::mt19937 eng;
	eng.seed(time(NULL));
	std::uniform_int_distribution<int> uid(0, INT_MAX);

	for (int i = 0; i < repeatCount; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr1[j] = uid(eng);
		}
		memcpy(arr2, arr1, sizeof(int) * n);
		qsort_3way(arr1, n, cmpDescending, 1);
		qsort_3way(arr2, n, cmpDescending, 1);
		for (int k = 0; k < n; k++)
		{
			ASSERT_EQ(arr1[k], arr2[k]);
		}
	}

	delete[] arr1;
	delete[] arr2;
}
