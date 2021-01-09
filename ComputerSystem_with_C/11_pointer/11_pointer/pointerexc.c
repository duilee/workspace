#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int pointexc01(void)
{
	char szData[50] = { 0 };

	scanf_s("%s", szData, sizeof(szData));
	int Length1 = strlen(szData);

	char *pszBuf1 = (char*)malloc(Length1 + 1);
	strcpy_s(pszBuf1, _msize(pszBuf1), szData);
	printf("%s\n", pszBuf1);

	scanf_s("%s", szData, sizeof(szData));
	int Length2 = strlen(szData);
	int length_both = Length1 + Length2;
	char *pszBuf2 = (char*)realloc(pszBuf1, length_both + 1);

	if (pszBuf2 == NULL)
	{
		puts("memory reallocate failed");
		free(pszBuf1);
		return 0;
	}

	strcpy_s(pszBuf2 + Length1, _msize(pszBuf2) - Length1, szData);

	printf("%s\n", pszBuf2);
	free(pszBuf2);

	return 0;
}

int pointerexc02(void)
{
	int numList = 0, numChar = 0, i = 0;
	scanf_s("%d", &numList);
	scanf_s("%d", &numChar);

	char **ppstrList = (char**)calloc(numList, sizeof(char*));

	for (i = 0; i < numList; i++)
	{
		*(ppstrList + i) = (char*)calloc(1 , sizeof(char) * numChar + 1);
		fflush(stdin);
		gets_s(*(ppstrList+i), numChar + 1); 
	}

	for (i = 0; i < numList; i++)
	{
		printf(*(ppstrList+i));
		free(*(ppstrList + i));
	}

	free(ppstrList);

	return 0;
}