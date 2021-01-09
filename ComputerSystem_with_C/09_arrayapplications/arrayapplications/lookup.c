#include <stdio.h>

//lookup table is generally faster

int lookup(int argc, char* argv[])
{
	// example with getting fees for 1~10 years old
	
	//set up ratings for each age
	double aRate[10] = {
		0.0, 0.1, 0.25, //1~3 years old 0%, 10%, 25%
		0.5, 0.5,		// 4~5 years old 50%
		0.6, 0.65,		// 6~7 years old 60%, 65%
		0.8, 0.82, 0.97 // 8~10 years old 80%, 82%, 97%
	};
	int nAge = 0, i = 0, nFee = 1000;

	//get the fee chart
	printf("fee chart\n");
	for (i = 1; i <= 10; ++i)
		printf("Age: %d, Fee:\t$%d\n", i, (int)(nFee * aRate[i - 1]));
	putchar('\n');

	printf("Insert Age. : ");
	scanf_s("%d", &nAge);
	if (nAge < 1)		nAge = 1;
	else if (nAge > 10)	nAge = 10;

	printf("final rate : $%d\n", (int)(nFee * aRate[nAge - 1]));
	putchar('\n');
	return 0;
}