#include <stdio.h>

int escseq(void)
{
	int x = 10;

	// char output on console
	putchar('B');
	// '/n' for new line
	putchar('\n');

	// print A
	printf("%c\n", 'A');
	// print value of x
	printf("x is %d. \n", x);
	return 0;
}