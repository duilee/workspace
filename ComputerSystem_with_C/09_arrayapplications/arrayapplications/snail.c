# include <stdio.h>

int snail(void)
{
	int aList[5][5] = { 0 };
	int i = 0, j = 0, nCounter = 0, nOffset = 1;
	int row = 0, col = 0;

	// divide into sections where row, col indexes are increasing and decreasing
	// number of iteration needed goes from 9, 7, 5, 3, 1
	for (i = 0; i < 5; ++i)
	{
		//compute iterations needed
		for (j = 0; j < (10 - (i * 2 + 1)); ++j)
		{
			//tells when to turn to filling in rows
			if (j < (10 - (i * 2 + 1)) / 2)
			{
				aList[row][col] = ++nCounter;
				col += nOffset;
			}
			else
			{
				aList[row][col] = ++nCounter;
				row += nOffset;
			}
		}

		// row index will moved by one of nOffset value, so subtract
		nOffset = -nOffset;
		row += nOffset;

		// need to move col to set the initial position for interation
		if (i % 2 == 0)
			col -= 1;
		else
			col += 1;

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