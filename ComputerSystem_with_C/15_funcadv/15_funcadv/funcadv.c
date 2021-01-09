#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GetName(char *pszName, int nSize)         // Write
{
	printf("Input your name: ");

	char szBuffer[32];
	gets_s(szBuffer, sizeof(szBuffer));
	strcpy_s(pszName, nSize, szBuffer);
}

void PrintName(const char *pszName)       //Read!!
{
	printf("Your name is %s.\n", pszName);
	// *pszName = 'A'
	// strcpy_s(pszName, 2, "A");
}

int main(void)
{
	/*
	char szName[32] = { 0 };
	GetName(szName, sizeof(szName));
	PrintName(szName);
	return 0;
	*/

	typearray();
}