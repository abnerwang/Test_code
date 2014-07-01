#include <iostream>
#include "Test.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int A[8];
	cout << "依次输入序列中的所有元素（8个）： ";
	for (int i = 0; i < 8; ++i)
		cin >> A[i];
	cout << MaxSubsequenceSum(A, 8) << endl;   /* 调用求最大子序列和的函数 */

	return 0;
}