#include <stdio.h>

int getsum2darray(void)
{
	int aList[3][4] = {
		{10, 20, 30},
		{40, 50, 60}
	};
	int i = 0, j = 0;

	for (i = 0; i < 3; ++i)
	{
		aList[2][i] = aList[0][i] + aList[1][i];
		aList[i][3] = aList[i][0] + aList[i][1] + aList[i][2];
	}

	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 4; ++j)
			printf("%d\t", aList[i][j]);

		putchar('\n');
	}
	return 0;
}