/*************************************************************************
	> File Name: wordlength.c
	> Author: 王小平 
	> Mail: abnerwang@yeah.net
	> Created Time: 一  3/30 19:52:04 2015
 ************************************************************************/

#include <stdio.h>

int wordlength(void);

int main()
{
	printf("Word Length: %d\n", wordlength());	
	return 0;
}

int wordlength(void)
{
	int i;
	unsigned v = (unsigned)~0;

	for (i = 1; (v = v >> 1) > 0; ++i)
		;
	return i;
}
