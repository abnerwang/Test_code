/*************************************************************************
	> File Name: hetoi.c
	> Author: 王小平 
	> Mail: abnerwang@yeah.net
	> Created Time: 五  3/27 14:07:38 2015
 ************************************************************************/

#include <stdio.h>
#define MAXDICA 100    /* maximum digit capacity of a number */

void getdigit(char s[], int lim);
int hetoi(char s[]);

/* convert a string of hexadecimal digits to integers */
int main()
{
	char num[MAXDICA];	
	int inte;

	getdigit(num, MAXDICA);
	inte = hetoi(num);
	printf("decimal digit: %d\n", inte);

	return 0;
}

/* getdigit: input a string of hexadecimal digits */
void getdigit(char s[], int lim)
{
	int i, c;

	i = 0;
	while(i < lim-1 && (((c = getchar()) >= '0' && c <= '9') 
				|| (c >= 'a' && c <= 'f') 
				|| (c >= 'A' && c <= 'F'))) {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
}

int hetoi(char s[])
{
	int i, n;

	i = 0;
	if (s[i] == '0') {         /* skip optional 0x or 0X */
		++i;
		if (s[i] == 'x' || s[i] == 'X')
			++i;
	}
	
	n = 0;		/* integer value to be returned */
	while(s[i] != '\0') {
		if (s[i] >= '0' && s[i] <= '9')
			n = 16 * n + (s[i] - '0');
		else if(s[i] >= 'a' && s[i] <= 'f')
			n = 16 * n + (s[i] - 'a' + 10);
		else if(s[i] >= 'A' && s[i] <= 'F')
			n = 16 * n + (s[i] - 'A' + 10);
		++i;
	}

	return n;
}

