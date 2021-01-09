#include <stdio.h>

int gettriangle(void)
{
	int i = 0, j = 0;

	for (i = 1; i < 6; ++i)
	{
		for (j = 0; j < i; ++j)
		{
			printf("*\t");
		}
		printf("\n");
	}
	return 0;
}