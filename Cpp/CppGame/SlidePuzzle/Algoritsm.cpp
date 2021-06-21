#include "Algoritsm.h"

#define N 4


// A utility function to count inversions in given
// array 'arr[]'. Note that this function can be
// optimized to work in O(n Log n) time. The idea
// here is to keep code small and simple.
int Algoritsm::GetInvCount(int arr[])
{
	int inv_count = 0;
	for (int i = 0; i < N * N - 1; i++)
	{
		for (int j = i + 1; j < N * N; j++)
		{
			// count pairs(i, j) such that i appears
			// before j, but i > j.
			if (arr[j] && arr[i] && arr[i] > arr[j])
				inv_count++;
		}
	}
	return inv_count;
}

// find Position of blank from bottom
int Algoritsm::FindXPosition(int puzzle[N][N])
{
	// start from bottom-right corner of matrix
	for (int i = N - 1; i >= 0; i--)
		for (int j = N - 1; j >= 0; j--)
			if (puzzle[i][j] == 0)
				return N - i;
	return -1;
}

// This function returns true if given
// instance of N*N - 1 puzzle is solvable
bool Algoritsm::IsSolvable(int puzzle[N][N])
{
	// Count inversions in given puzzle
	int invCount = GetInvCount((int*)puzzle);

	// If grid is odd, return true if inversion
	// count is even.
	if (N & 1)
		return !(invCount & 1);

	else     // grid is even
	{
		int pos = FindXPosition(puzzle);
		if (pos & 1)
			return !(invCount & 1);
		else
			return invCount & 1;
	}
}