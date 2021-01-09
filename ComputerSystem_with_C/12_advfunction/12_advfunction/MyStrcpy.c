#include <stdio.h>

int MyStrcpy(char *pszDst, int nDstSize, char *pszSrc)
{
	int i = 0, nLenSrc = 0;
	
	nLenSrc = strlen(pszSrc);
	if (nLenSrc + 1 > nDstSize)
		return nDstSize - (nLenSrc + 1);

	while (pszSrc[i] != '\0')
	{
		pszDst[i] = pszSrc[i];
		++i;
	}

	pszDst[i] = '\0';

	return nLenSrc;
}