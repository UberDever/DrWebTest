#include "pch.h"
#include "../DrWebTest/MatrixInCpp.hpp"

TEST(SortMatrixInCpp, CheckSortedMatrix3x5) {
	constexpr int M = 3;
	constexpr int N = 5;
	Matrix<int, M, N> matrix = { 8, 9, 4, 1, 2,
								 3, 5, 0, -3, 4,
								 -2, 12, -1, 0, -9 };
	matrix = generate_matrix(matrix);
	testing::internal::CaptureStdout();
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", matrix[i][j]);
		}
	}
	std::string output1 = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(output1.c_str(), "12 8 4 4 1 " "9 3 2 0 0 " "5 -1 -2 -3 -9 ");
}

TEST(SortMatrixInCpp, CheckSortedMatrix6x6) {
	constexpr int M = 6;
	constexpr int N = 6;
	Matrix<int, M, N> matrix = { 7, 0,	5, 7, -2, -2,
								 6, -1, -1, 0, 10, -7,
								-6, 10, -5, 4, 9, 2,
								 1, -8, -10, -8, 10, 2,
								-5, 5,	3, 2, 7, 9,
								-7, 1,	3, 3, 3, -1 };
	matrix = generate_matrix(matrix);
	testing::internal::CaptureStdout();
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", matrix[i][j]);
		}
	}
	std::string output1 = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(output1.c_str(), "10 10 9 7 7 5 " "10 6 5 4 3 2 " "9 3 3 2 1 1 " "7 2 0 -1 -1 -5 " "3 0 -1 -2 -5 -6 " "-2 -7 -7 -8 -8 -10 ");
}