#include <stdio.h>

int GetData(void)
{
	int nInput = 0;

	printf("Insert integer. : ");
	scanf_s("%d", &nInput);

	return nInput;
}

int GetMax(int a, int b, int c)
{
	int nMax = a, i = 0;
	int l_aList[3] = { a, b, c };

	for (i = 1; i < 3; ++i)
		if (l_aList[i] > nMax)
			nMax = l_aList[i];
	
	return nMax;
}

int PrintData(int a, int b, int c, int d)
{
	printf("%d is the max among %d, %d, %d. \n",
		d, a, b, c);
	return 0;
}

int splitcode(void)
{
	int aList[3] = { 0 };
	int nMax = -9999, i = 0;

	// insert input
	for (i = 0; i < 3; ++i)
		aList[i] = GetData();

	//calculate max
	nMax = GetMax(aList[0], aList[1], aList[2]);

	//print
	PrintData(aList[0], aList[1], aList[2], nMax);
	return 0;
}