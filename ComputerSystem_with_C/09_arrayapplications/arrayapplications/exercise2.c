#include <stdio.h>

//filling in 5 * 5 matrix with counterclockwise action

int exercise2(void)
{
	int aList[5][5] = { 0 };
	int x = 5, y = 0, nCounter = 0;
	int i = 0, j = 0, nLength = 9, nDirection = -1;

	for (nLength = 9; nLength > 0; nLength -= 2)
	{
		for (i = 0; i < nLength; ++i)
		{
			if (i < nLength / 2 + 1) x += nDirection;
			else
			{
				// change direction from row to col once
				if (i < nLength / 2 + 2) nDirection = -nDirection;
				y += nDirection;
			}
			aList[y][x] = ++nCounter;
		}
	}

	for (i = 0; i < 5; ++i)
	{
		for (j = 0; j < 5; ++j)
			printf("%d\t", aList[i][j]);
		putchar('\n');
	}

	return 0;
}