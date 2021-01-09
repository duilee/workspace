#include <stdio.h>

int ifmax(void)
{
	// getting max of three integers using if
	int a, b, c, nMax;
	printf("insert three integers: ");
	scanf_s("%d%d%d", &a, &b, &c);

	nMax = a;
	if (b > nMax)
		nMax = b;

	if (c > nMax)
		nMax = c;

	printf("Max: %d \n", nMax);
	return 0;
}