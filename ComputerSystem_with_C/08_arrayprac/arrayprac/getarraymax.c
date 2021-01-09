#include <stdio.h>

int getarraymax(void)
{
	int aList[5] = { 30, 40, 10, 50, 20 };
	int i = 0;

	for (i = 0; i < 5; ++i)
	{
		if (aList[0] <= aList[i])
			aList[0] = aList[i];
	}

	for (i = 0; i < 5; ++i)
		printf("%d\t", aList[i]);
	putchar('\n');

	printf("MAX: %d\n", aList[0]);
	return 0;
}