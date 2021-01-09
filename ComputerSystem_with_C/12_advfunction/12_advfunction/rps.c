#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// playing rock(0) paper(1) sissors(2)

void rsp(int nInput)
{
	int nComp = 0;
	srand((unsigned)time(NULL));
	nComp = rand() % 3;
	printf("%d\n", nComp);

	if ((nInput - nComp) == 1 || (nInput - nComp) == -2)
		puts("You win!");
	else if (nInput == nComp)
		puts("Draw!");
	else
		puts("You lose :(");
}

int playrsp(void)
{
	int nUser = 0;
	printf("Your move: ");
	scanf_s("%d", &nUser);

	rsp(nUser);

	return 0;
}