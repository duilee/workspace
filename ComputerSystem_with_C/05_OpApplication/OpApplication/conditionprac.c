#include <stdio.h>

int conditionprac(void)
{
	int nInput = 0;
	printf("Insert your score out of 100: ");
	scanf_s("%d", &nInput);


	printf("result: %s \n", nInput > 70 ? ("Pass") : ("Fail"));

	return 0;
}