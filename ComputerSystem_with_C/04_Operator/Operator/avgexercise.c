#include <stdio.h>

int avgexercise(void)
{
	int x = 0, y = 0;
	printf("insert two integers: ");

	scanf_s("%d%d", &x, &y);

	printf("AVG: %.2f \n", (x + y) / 2.0);

	return 0;
}