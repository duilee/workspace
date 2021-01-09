#include <stdio.h>

int getfare(void)
{
	//simple if statment
	int nAge;
	double nFare = 1000;
	printf("enter your age: ");
	scanf_s("%d", &nAge);

	if (nAge < 20)
		nFare *= 0.75;

	printf("Fare Price: $ %.0f\n", nFare);

	return 0;
}