#include <stdio.h>
#include <string.h>

void funcstrpbrk(void)
{
	char szBuffer[128] = { 0 };
	char szSet[128] = { 0 };
	char *pszStart = szBuffer;

	// get string to be searched
	printf("Input String: ");
	gets(szBuffer);

	// get characters to search
	printf("Input character set: ");
	gets(szSet);

	// see if any matches
	while ((pszStart = strpbrk(pszStart, szSet)) != NULL)
	{
		printf("[%p] Index: %d, %c \n",
			pszStart, pszStart - szBuffer, *pszStart);

		// move one index to search for more
		pszStart++;
	}
}