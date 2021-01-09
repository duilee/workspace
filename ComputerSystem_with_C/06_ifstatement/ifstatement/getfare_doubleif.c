#include <stdio.h>

int getfare_doubleif(void)
{	
	// binary if statements
	// get the middle or avg value to somewhat equally divide 
	int nAge;
	double nFare = 1000;

	printf("insert your age: ");
	scanf_s("%d", &nAge);

	if (nAge <= 13)
	{
		nFare *= 0.5;
		if (nAge <= 3)
			nFare = 0;
	}
	else
	{
		if (nAge <= 19)
			nFare *= 0.75;
	}

	printf("Fare Price: %.0f \n", nFare);
	return 0;
}