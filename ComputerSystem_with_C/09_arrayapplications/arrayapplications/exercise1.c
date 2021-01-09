#include <stdio.h>

int exercise1(void)
{
	//fill in 1 ~ 25 in zigzag manner by columns

	int aList[5][5] = { 0 };
	int i = 0, j = 0, nCounter = 0;

	for (i = 0; i < 5; ++i)
	{
		if (i % 2 == 0) //distinction between odd and even column
		{
			//even column
			for (j = 0; j < 5; ++j)
				aList[j][i] = ++nCounter;
		}
		else
		{
			//odd column, fill in opposit way
			for (j = 0; j < 5; ++j)
				aList[4-j][i] = ++nCounter;
		}
	}


	//print

	for (i = 0; i < 5; ++i)
	{
		for (j = 0; j < 5; ++j)
			printf("%d\t", aList[i][j]);
		putchar('\n');
	}
	return 0;
}