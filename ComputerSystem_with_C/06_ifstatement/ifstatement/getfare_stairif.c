#include <stdio.h>

int getfare_stairif(void)
{
	// uses stair like if statements, rather inefficient
	int nAge;
	double nRate = 0.0;

	printf("insert your age: ");
	scanf_s("%d", &nAge);
	
	if (nAge <= 3) nRate = 1.0;
	else if (nAge <= 13) nRate = 0.5;
	else if (nAge <= 19) nRate = 0.25;
	else if (nAge <= 19) nRate = 0.25;
	else if (nAge >= 65) nRate = 1.0;

	printf("Fare Price: %d\n", (int)(1000 * (1 - nRate)));

	return 0;

}