#include <stdio.h>

int maxbinary(void)
{
	// get max value as if tournament
	int nMax = 0;
	int a, b, c;
	//receive inputs
	printf("insert 3 numbers with space in between: ");
	scanf_s("%d%d%d", &a, &b, &c);

	// compare a and b, then to c
	nMax = a > b ? a : b;
	nMax = nMax > c ? nMax : c;

	printf("Max: %d \n", nMax);
	return 0;
}