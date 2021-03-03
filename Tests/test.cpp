#include "pch.h"
#include "../DrWebTest/MatrixInC.h"

TEST(SortMatrixInC, CheckNullMatrix) {
	int** matrix = NULL;
	EXPECT_TRUE(generate_matrix((const int**)matrix, 0, 0) == NULL);
}

TEST(SortMatrixInC, CheckNonPositiveSizes) {
	int** matrix = NULL;
	int m = -1, n = 0;
	EXPECT_TRUE(generate_matrix((const int**)matrix, m, n) == NULL);
}
TEST(SortMatrixInC, CheckArrayCollumn) {
	int** matrix = NULL;
	int m = 1, n = 10;
	matrix = alloc_matrix(m, n);

	int arr[] = { 5, 2, 9, 8, 7, 4, 1, 0, 3, 6 };
	memcpy(matrix[0], arr, sizeof(arr));

	int** matrix_sorted = generate_matrix((const int**)matrix, m, n);

	testing::internal::CaptureStdout();
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", matrix_sorted[0][i]);
	}
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(output.c_str(), "9 8 7 6 5 4 3 2 1 0 ");
	free(matrix);
	free(matrix_sorted);
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
		qsort_3way(arr1, n, cmpDescending);
		qsort_3way(arr2, n, cmpDescending);
		for (int k = 0; k < n; k++)
		{
			ASSERT_EQ(arr1[k], arr2[k]);
		}
	}

	delete[] arr1;
	delete[] arr2;
}

