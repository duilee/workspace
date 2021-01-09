#include <stdio.h>

int getcumsum(void)
{
	int i = 1, nTotal = 0;

	while (i < 11)
	{
		nTotal += i;
		++i;
	}

	printf("%d \n", nTotal);
	
	return 0;
}