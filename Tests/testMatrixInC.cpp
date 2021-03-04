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
TEST(SortMatrixInC, CheckSortedArrayCollumn) {
	int** matrix = NULL;
	int m = 1, n = 10;
	matrix = alloc_matrix(m, n);

	int arr[] = { 5, 2, 9, 8, 7, 4, 1, 0, 3, 6 };
	memcpy(matrix[0], arr, sizeof(arr));

	int** matrix_sorted = generate_matrix((const int**)matrix, m, n);

	testing::internal::CaptureStdout();
	for (int i = 0; i < m * n; i++)
	{
		printf("%d ", matrix_sorted[0][i]);
	}
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(output.c_str(), "9 8 7 6 5 4 3 2 1 0 ");
	free(matrix);
	free(matrix_sorted);
}

TEST(SortMatrixInC, CheckSortedArrayRow) {
	int** matrix = NULL;
	int m = 10, n = 1;
	matrix = alloc_matrix(m, n);

	int arr[] = { 5, 2, 9, 8, 7, 4, 1, 0, 3, 6 };
	for (int i = 0; i < m; i++)
	{
		matrix[i][0] = arr[i];
	}

	int** matrix_sorted = generate_matrix((const int**)matrix, m, n);

	testing::internal::CaptureStdout();
	for (int i = 0; i < m * n; i++)
	{
		printf("%d ", matrix_sorted[i][0]);
	}
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(output.c_str(), "9 8 7 6 5 4 3 2 1 0 ");
	free(matrix);
	free(matrix_sorted);
}

TEST(SortMatrixInC, CheckSortedMatrix3x3) {
	int** matrix = NULL;
	int m = 3, n = 3;
	matrix = alloc_matrix(m, n);

	int arr[] = { 9, 8, 6,
				  4, 3, 1,
				  0, 2, 9 };
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = arr[i * n + j];
		}
	}

	testing::internal::CaptureStdout();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", matrix[i][j]);
		}
	}
	std::string output0 = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(output0.c_str(), "9 8 6 4 3 1 0 2 9 ");

	int** matrix_sorted = generate_matrix((const int**)matrix, m, n);

	testing::internal::CaptureStdout();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", matrix_sorted[i][j]);
		}
	}
	std::string output1 = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(output1.c_str(), "9 9 8 6 4 3 2 1 0 ");
	free(matrix);
	free(matrix_sorted);
}

TEST(SortMatrixInC, CheckSortedMatrix6x6) {
	int** matrix = NULL;
	int m = 6, n = 6;
	matrix = alloc_matrix(m, n);

	int arr[] = { 7, 0,	5, 7, -2, -2,
				  6, -1, -1, 0, 10, -7,
				 -6, 10, -5, 4, 9, 2,
				  1, -8, -10, -8, 10, 2,
				 -5, 5,	3, 2, 7, 9,
				 -7, 1,	3, 3, 3, -1 };
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = arr[i * n + j];
		}
	}

	testing::internal::CaptureStdout();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", matrix[i][j]);
		}
	}
	std::string output0 = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(output0.c_str(), "7 0 5 7 -2 -2 " "6 -1 -1 0 10 -7 " "-6 10 -5 4 9 2 " "1 -8 -10 -8 10 2 " "-5 5 3 2 7 9 " "-7 1 3 3 3 -1 ");

	int** matrix_sorted = generate_matrix((const int**)matrix, m, n);

	testing::internal::CaptureStdout();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", matrix_sorted[i][j]);
		}
	}
	std::string output1 = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(output1.c_str(), "10 10 9 7 7 5 " "10 6 5 4 3 2 " "9 3 3 2 1 1 " "7 2 0 -1 -1 -5 " "3 0 -1 -2 -5 -6 " "-2 -7 -7 -8 -8 -10 ");
	free(matrix);
	free(matrix_sorted);
}

