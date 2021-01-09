#include <stdio.h>

int getpyramid(void)
{
	int i = 0, j = 0;

	for (i = 0; i < 5; ++i)
	{
		for (j = 0; j < 5 + i; ++j)
		{
			if (i+j >= 4) printf("*\t");
			else putchar('\t');
		}
		printf("\n");
	}
	return 0;
}