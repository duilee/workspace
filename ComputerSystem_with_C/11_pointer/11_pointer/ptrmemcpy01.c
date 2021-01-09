#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ptrmemcpy(void)
{
	char szBuffer[12] = { "HelloWorld" };
	char szNewBuffer[12] = { 0 };

	// copy only 4 bytes
	memcpy(szNewBuffer, szBuffer, 4);
	puts(szNewBuffer);

	// copy only 4 bytes
	memcpy(szNewBuffer, szBuffer, 6);
	puts(szNewBuffer);

	// copy only 4 bytes
	memcpy(szNewBuffer, szBuffer, sizeof(szBuffer));
	puts(szNewBuffer);
	return 0;
}

int ptrprac(void)
{
	char szBuffer[12] = { "HelloWorld" };
	char *pszData = NULL;

	pszData = (char*)malloc(sizeof(char) * 12);
	memcpy(pszData, szBuffer, sizeof(szBuffer));
	puts(pszData);
	free(pszData);
	return 0;
}