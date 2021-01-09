#include <stdio.h>

/* get 5 integers as input and get max
 if input < 0 then replace with 0
 if input > 100 then replace with 100
*/

int max5input(void)
{
	int a, b, c, d, e, nMax;
	scanf_s("%d%d%d%d%d", &a, &b, &c, &d, &e);

	nMax = a;

	if (b > nMax) nMax = b;
	if (c > nMax) nMax = c;
	if (d > nMax) nMax = d;
	if (e > nMax) nMax = e;

	if (nMax > 100) nMax = 100;
	else if (nMax < 0) nMax = 0;

	printf("Max: %d \n", nMax);
	return 0;
}
