#pragma once
#include <stdlib.h>
#include <random>
#include <time.h>

typedef int (*comp_t)(int, int);

static int cmpAscending(int a, int b)
{
	return a - b;
}

static int cmpDescending(int a, int b)
{
	return b - a;
}

static std::pair<int, int> partition3(int* array, int lowerBound, int upperBound, comp_t cmpFunc, int stride) {
	int pivot = array[lowerBound];
	int j = lowerBound;
	int k = lowerBound;
	// Three way partition means that we have this set as output:
	// [  < pivot  | == pivot  |  > pivot  ]
	//			   j           k
	// a[i], i < j -> a[i] < pivot
	// a[i], j <= i <= k -> a[i] == pivot
	// a[i], i > k -> a[i] > pivot
	for (int i = lowerBound + stride; i <= upperBound; i += stride) {
		const int compValue = cmpFunc(array[i], pivot);
		if (compValue < 0) // array[i] < pivot
		{
			std::swap(array[i], array[j]);
			j += stride;
			k += stride;
			std::swap(array[i], array[k]);
		}
		else if (compValue == 0) // array[i] == pivot
		{
			k += stride;
			std::swap(array[i], array[k]);
		}
	}
	return { j, k };
}

static void qsort_3way_recursive(int* array, int lowerBound, int upperBound, comp_t cmpFunc, int stride) {
	while (lowerBound < upperBound)
	{
		// RNG Pivot method
		/*
		// Preparing rng engine
		std::mt19937 eng;
		eng.seed(time(NULL));
		std::uniform_int_distribution<int> uid(lowerBound, upperBound); // [lowerBound, upperBound]

		int randomPivot = uid(eng);
		*/

		// Three median pivot method (faster than random pivot method)
		int mediumIndex = (lowerBound + upperBound) / stride / 2 * stride;
		int F = array[lowerBound];
		int M = array[mediumIndex];
		int L = array[upperBound];

		bool FgtM = F > M;
		bool FgtL = F > L;
		bool MgtL = M > L;

		// Used DNF for quick median retrieval
		int medianPivot = 0;
		if ((FgtM && FgtL && MgtL) || (!FgtM && !FgtL && !MgtL))
			medianPivot = mediumIndex;
		else if ((!FgtM && !FgtL && MgtL) || (FgtM && FgtL && !MgtL))
			medianPivot = upperBound;
		else if ((!FgtM && FgtL && MgtL) || (FgtM && !FgtL && !MgtL))
			medianPivot = lowerBound;
		// else impossible case

		// Swapping lower and pivot for region handling
		std::swap(array[lowerBound], array[medianPivot]);
		std::pair<int, int> bounds = partition3(array, lowerBound, upperBound, cmpFunc, stride);

		// Chosing, what partition is preferable - this ensures O(n*logn) on every set with
		// low recursion depth. If I add heap sort for high recursion depth, I will get Introsort, but this is
		// too much for this project, performance is already pretty good
		if ((bounds.first - lowerBound) < (upperBound - bounds.second))
		{
			qsort_3way_recursive(array, lowerBound, bounds.first - stride, cmpFunc, stride);
			lowerBound = bounds.first + stride;
		}
		else
		{
			qsort_3way_recursive(array, bounds.second + stride, upperBound, cmpFunc, stride);
			upperBound = bounds.second - stride;
		}
	}


}

static void qsort_3way(int* array, int numOfElements, comp_t cmpFunc, int stride)
{
	qsort_3way_recursive(array, 0, (numOfElements - 1) * stride, cmpFunc, stride);
}
