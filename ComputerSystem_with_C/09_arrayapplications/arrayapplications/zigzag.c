#include <stdio.h>

int zigzag(void)
{
	//fill in 1 ~ 25 in zigzag manner
	
	int aList[5][5] = { 0 };
	int i = 0, j = 0, nCounter = 0;

	for (i = 0; i < 5; ++i)
	{
		if (i % 2 == 0) //distinction between odd and even row
		{
			//even row
			for (j = 0; j < 5; ++j)
			{
				aList[i][j] = ++nCounter;
			}
		}
		else
		{
			//odd row, fill in opposite way
			for (j = 0; j < 5; ++j)
			{
				aList[i][4-j] = ++nCounter;
			}
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