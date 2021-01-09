#include <stdio.h>

int getcharprac(void)
{
	/* use getchar() to have input : 'Test' and output: 'e'*/
	char x = 0;

	printf("Input :");
	getchar();
	x = getchar();

	printf("Output: %c\n", x);

	return 0;


}