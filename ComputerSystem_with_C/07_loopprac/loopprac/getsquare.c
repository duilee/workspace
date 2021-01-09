#include <stdio.h>

int getsquare(void)
{
	int i = 0, j = 0;

	while (i < 5)
	{
		while (j < 5)
		{
			printf("*\t");
			++j;
		}
		++i;
		printf("\n");
		j = 0;
	}
	return 0;
}