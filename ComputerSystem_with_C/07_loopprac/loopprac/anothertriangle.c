#include <stdio.h>

int anothertriangle(void)
{
	int i = 0, j = 0, k = 0;

	for (i = 1; i < 6; ++i)
	{
		for (k = 0; k < (5 - i); ++k)
		{
			printf("\t");
		}

		for (j = 0; j < i; ++j)
		{
			printf("*\t");
		}
		printf("\n");
	}
	return 0;
}