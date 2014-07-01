/* ���β��Խ�ϵݹ�˼������������к� */
#include "Test.h"
int MaxSubSum(const int A[], int Left, int Right)
{
	if (Left == Right)
		return A[Left];

	int Center;
	Center = (Left + Right) / 2;    /* ����ֽ�� */
	
	/* ���շ��β��Խ����ⲻ��һ��Ϊ�������ݹ�ֱ�����벿�ֺ��Ұ벿�ֵ���������к� */
	int MaxLeftSum = MaxSubSum(A, Left, Center);
	int MaxRightSum = MaxSubSum(A, Center + 1, Right);

	/* ������벿�ֺ��Ұ벿�ֵ���������к� */
	/* ������벿���������а������һ��Ԫ�ص���������к� */
	int MaxLeftBorderSum = A[Center], LeftBorderSum = A[Center];
	for (int i = Center - 1; i >= Left; --i) {
		LeftBorderSum += A[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}

	/* Ȼ�����Ұ벿���������а�����һ��Ԫ�ص���������к� */
	int MaxRightBorderSum = A[Center + 1], RightBorderSum = A[Center + 1];
	for (int i = Center + 2; i <= Right; ++i) {
		RightBorderSum += A[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}

	/* ������벿����������к͡��Ұ벿�ֵ���������к�
	 * �Լ������벿�ֺ��Ұ벿�ֵ���������к�����֮��
	 * �������
	 */
	return Max3(MaxLeftSum, MaxRightSum,
		MaxLeftBorderSum + MaxRightBorderSum);
}