#include <stdio.h>
#include <string.h>

char* mystrcat(char *pszDst, char *pszSrc)
{
	//find the end of string
	while (*pszDst != '\0')
		++pszDst;

	//append new string at the end
	while (*pszSrc != '\0')
		*pszDst++ = *pszSrc++;

	// add NULL at the end
	*++pszDst = '\0';

	//return the adress of last string
	return --pszDst;
}

int funcstrcat(void)
{
	char szPath[128] = { 0 };
	char *pszEnd = NULL;

	// attach new string
	pszEnd = mystrcat(szPath, "C:\\Program Files\\");
	pszEnd = mystrcat(pszEnd, "CHS\\");
	pszEnd = mystrcat(pszEnd, "C Programming");

	puts(szPath);
	return 0;
}