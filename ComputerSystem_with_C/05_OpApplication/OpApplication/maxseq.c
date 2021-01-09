#include <stdio.h>

int maxseq(void)
{
	int nMax = -9999, nInput = 0;

	scanf_s("%d", &nInput);
	nMax = nInput > nMax ? nInput : nMax;

	scanf_s("%d", &nInput);
	nMax = nInput > nMax ? nInput : nMax;

	scanf_s("%d", &nInput);
	nMax = nInput > nMax ? nInput : nMax;

	printf("Max: %d \n", nMax);
	return 0;
}