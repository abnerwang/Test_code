#include "Test.h"
int MaxSubsequenceSum(const int A[], int N)
{
	return MaxSubSum(A, 0, N - 1);
}