#include <stdio.h>

int secondtotime(void)
{
	int nInput = 0, sec = 0, min = 0, hr = 0;
	// get input as seconds
	scanf_s("%d", &nInput);

	// reminder after dividing by 60 is seconds
	sec = nInput % 60;

	//reminder from division by 60 will be minutes
	min = nInput / 60 % 60;
	// get hour
	hr = nInput / 60 / 60;
	
	printf("%d is %02d hour %02d minutes %02d seconds \n", nInput, hr, min, sec);

	return 0;
}