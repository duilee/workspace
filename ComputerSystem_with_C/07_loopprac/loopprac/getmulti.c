#include <stdio.h>

int getmulti(void)
{
	int nInput = 0, i = 1, mul;
	scanf_s("%d", &nInput);

	if (nInput < 2 || nInput > 9)
		printf("ERROR \n");
	else
		while (i < 10)
		{
			mul = i * nInput;
			printf("%d * %d = %d \n", nInput, i, mul);
			++i;
		}

	return 0;
}