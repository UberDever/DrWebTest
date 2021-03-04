#pragma once
#include <array>
#include "QSort.h"

template <class T, int M, int N>
using Matrix = std::array<std::array<T, N>, M>;

// Signature is straightforward
template <class T, int M, int N>
Matrix<T, M, N> generate_matrix(const Matrix<T, M, N> matrix)
{
	Matrix<T, M, N> matrix_out;
	// Flatten the matrix array
	// It requires additional memory, but this is the easiest and compatable way
	// Can be avoided by wrapping the std::array in class and pretending it multidimensional
	int* matrix_flat = new int[M * N];
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			matrix_flat[i * N + j] = matrix[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		qsort_3way(matrix_flat + i, M, cmpDescending, N);
	}
	for (int i = 0; i < M; i++)
	{
		qsort_3way(matrix_flat + i * N, N, cmpDescending, 1);
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			matrix_out[i][j] = matrix_flat[i * N + j];
		}
	}
	delete[] matrix_flat;
	return matrix_out;
}