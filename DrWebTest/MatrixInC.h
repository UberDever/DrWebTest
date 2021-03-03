#pragma once
#include "QSort.h"

int comp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

static int** alloc_matrix(int m, int n)
{
	int** matrix = NULL;
	matrix = (int**)malloc(m * sizeof(int*));
	if (matrix == NULL)
		return NULL;
	for (int i = 0; i < m; i++)
	{
		matrix[i] = (int*)malloc(n * sizeof(int));
	}
	return matrix;
}

/*
	Function assumes, that given matrix structure is as follows:
		int** matrix =
			int* p1 -> [e1, e2, ... eN]
			int* p2 -> [e1, e2, ... eN]
			...
			int* pM -> [e1, e2, ... eN]
		(So, basically, array of pointers of size m,
		 that points to m allocated memory chunks with size sizeof(int) * n)

	Whereas, function returns matrix, structured as follows:
		int** matrix_out =
			int* p1 -> [e1, e2, ... eN]
			int* p2 -> [eN+1, eN+2 ... e2N]
			...
			int* pM -> [... eMN]
		(So, basically, array of pointers of size m,
		 that points to 1 allocated memory chunk with size sizeof(int) * n * m with respectfull offsets)

	This was done, because matrix traversal must go
	through columns and also through rows without dereferencing and cache misses.

	Freeing memory in first case:
		for (int i = 0; i < m; i++)
			free(matrix_out[i]);
		free(matrix_out);

	Freeing memory in second case:
		free(matrix_out[0]); // free(*matrix_out)
		free(matrix_out);
*/

/// <summary>
/// generate_matrix() - Generates sorted matrix from given and returns pointer to it.
/// </summary>
/// <param name="matrix">Matrix to be sorted</param>
/// <param name="m">Count of row elements in matrix (also count of columns)</param>
/// <param name="n">Count of column elements in matrix (also count of rows)</param>
/// <returns></returns>
static int** generate_matrix(const int** matrix, size_t m, size_t n)
{
	if (matrix == NULL)
		return NULL;
	if ((m > 0 && n > 0) != true)
		return NULL;

	int** matrix_out = (int**)malloc(m * sizeof(int*));
	if (matrix_out == NULL)
		return NULL;
	int* matrix_flat = (int*)malloc(m * n * sizeof(int));
	if (matrix_flat == NULL)
		return NULL;
	for (int i = 0; i < m; i++)
	{
		size_t offset = (i * n);
		matrix_out[i] = matrix_flat + offset;
		memcpy(matrix_flat + offset, matrix[i], sizeof(int) * n);
	}
	//memcpy(matrix_out, matrix, sizeof(int) * m * n);

	for (int i = 0; i < m; i++)
	{
		qsort_3way(matrix_out[i], n, cmpDescending);
	}

	return matrix_out;
}