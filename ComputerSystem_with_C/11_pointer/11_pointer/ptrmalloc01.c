#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int ptrmalloc01(void)
{
	int *pList = NULL, i = 0;

	//use malloc for dynamic allocation
	pList = (int*)malloc(sizeof(int) * 3);

	pList[0] = 10;
	pList[1] = 20;
	pList[2] = 30;

	for (i = 0; i < 3; ++i)
		printf("%d\n", pList[i]);

	free(pList);
	return 0;
}

int ptrmeminit01(void)
{
	int *pList = NULL, *pNewList = NULL;
	int aList[3] = { 0 };

	// dynamic allocation and set to zero
	pList = (int*)malloc(sizeof(int) * 3);
	memset(pList, 0, sizeof(int) * 3);

	// get memory allocation preset to 0
	pNewList = (int*)calloc(3, sizeof(int));

	free(pList);
	free(pNewList);

	return 0;
}

int ptrmeminit02(void)
{
	// compiler automatically set the size
	char szBuffer[] = { "Hello" };
	
	// pointer with address of string "hello"
	// this "hello" is not the same as szBuffer
	char *pszBuffer = "Hello";

	//string assignment through dynamic allocation
	char *pszData = NULL;

	pszData = (char*)malloc(sizeof(char) * 6);
	pszData[0] = 'H';
	pszData[1] = 'e';
	pszData[2] = 'l';
	pszData[3] = 'l';
	pszData[4] = 'o';
	pszData[5] = '\0';

	puts(szBuffer);
	puts(pszBuffer);
	puts(pszData);

	free(pszData);
	return 0;
}

int ptrrealloc(void)
{
	char *pszBuffer = NULL, *pszNewBuffer = NULL;

	//allocate 14 bytes
	pszBuffer = (char*)malloc(12);
	sprintf(pszBuffer, "%s", "TestString");
	printf("[%p] %d %s\n", pszBuffer, _msize(pszBuffer), pszBuffer);

	//try reallocation
	pszNewBuffer = (char*)realloc(pszBuffer, 32);
	//if reallocation fails, free memory
	if (pszNewBuffer == NULL)
		free(pszBuffer);
	sprintf(pszNewBuffer, "%s", "TestStringData");
	printf("[%p] %d %s\n", pszNewBuffer, _msize(pszNewBuffer), pszNewBuffer);

	free(pszNewBuffer);

	return 0;
}