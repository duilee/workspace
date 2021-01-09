#include <stdio.h>

int iter01(void)
{
	int nInput;
	scanf_s("%d", &nInput);

	while (nInput > 0)
	{
		printf("*");
		nInput -= 1;
	}
	
	printf("\n");


	return 0;
}