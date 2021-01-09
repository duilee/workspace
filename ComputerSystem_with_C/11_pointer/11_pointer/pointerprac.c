#include <stdio.h>
#include <string.h>

int pointer01(void)
{
	int x = 10;
	// pointer variable for int x
	int *pnData = &x;

	printf("x : %d\n", x);

	// access memory address of x
	*pnData = 20;

	printf("x : %d\n", x);
	return 0;
}

int ptrstring02(void)
{
	char szBuffer[16] = { "Hello" };
	char *pszData = szBuffer;

	//get the length of string
	while (*pszData != '\0')
		pszData++;

	// subtract two location address to get length
	printf("Length : %d\n", pszData - szBuffer);
	return 0;
}

int stringptr(void)
{
	char szBuffer[32] = { "You are a girl." };
	char *pszData = szBuffer + 4;

	printf("%c\n", szBuffer[0]);
	printf("%c\n", pszData[0]);
	printf("%c\n", pszData[6]);

	printf("%s\n", szBuffer + 4);
	printf("%s\n", pszData);
	printf("%s\n", pszData + 4);

	return 0;
}

