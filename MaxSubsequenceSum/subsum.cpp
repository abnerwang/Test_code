/* 分治策略结合递归思想求最大子序列和 */
#include "Test.h"
int MaxSubSum(const int A[], int Left, int Right)
{
	if (Left == Right)
		return A[Left];

	int Center;
	Center = (Left + Right) / 2;    /* 计算分界点 */
	
	/* 按照分治策略将问题不断一分为二，按递归分别求左半部分和右半部分的最大子序列和 */
	int MaxLeftSum = MaxSubSum(A, Left, Center);
	int MaxRightSum = MaxSubSum(A, Center + 1, Right);

	/* 求横跨左半部分和右半部分的最大子序列和 */
	/* 先求左半部分子序列中包含最后一个元素的最大子序列和 */
	int MaxLeftBorderSum = A[Center], LeftBorderSum = A[Center];
	for (int i = Center - 1; i >= Left; --i) {
		LeftBorderSum += A[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}

	/* 然后求右半部分子序列中包含第一个元素的最大子序列和 */
	int MaxRightBorderSum = A[Center + 1], RightBorderSum = A[Center + 1];
	for (int i = Center + 2; i <= Right; ++i) {
		RightBorderSum += A[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}

	/* 返回左半部分最大子序列和、右半部分的最大子序列和
	 * 以及横跨左半部分和右半部分的最大子序列和三者之中
	 * 的最大者
	 */
	return Max3(MaxLeftSum, MaxRightSum,
		MaxLeftBorderSum + MaxRightBorderSum);
}