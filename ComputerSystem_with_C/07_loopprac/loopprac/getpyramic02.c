#include <stdio.h>

int getpyramid02(void)
{
	int i = 0, j = 0;

	for (i = 0; i < 5; ++i)
	{
		for (j = 0; j < 5; ++j)
		{
			if (i + j >= 4) printf("*\t\t");
			else printf("\t");
		}
		putchar('\n');
	}
	return 0;
}