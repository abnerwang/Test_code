#include <iostream>
#include "Test.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int A[8];
	cout << "�������������е�����Ԫ�أ�8������ ";
	for (int i = 0; i < 8; ++i)
		cin >> A[i];
	cout << MaxSubsequenceSum(A, 8) << endl;   /* ��������������к͵ĺ��� */

	return 0;
}