#include <stdio.h>
#include <stdlib.h>

void utilfunc(void)
{
	char szBuffer[32];
	int nResult = 0;

	printf("Input string: ");
	gets(szBuffer);

	nResult = atoi(szBuffer);
	printf("%d\n", nResult);

	//other util fuctions include
	/*
	atol(), atof(), time(), localtime(), ctime()
	srand(), rand(), system(), exit()
	*/
}