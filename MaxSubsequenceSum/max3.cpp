#include "Test.h"
int Max3(int i, int j, int k)
{
	return (k > i) ? k : (i = (i > j) ? i : j);
}