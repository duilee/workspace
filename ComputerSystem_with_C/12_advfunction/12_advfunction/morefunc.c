#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mystrstr(char *pstrList, char *pstrSearch)
{
	char *pResult = strstr(pstrList, pstrSearch);

	if (pResult == NULL)
		return -1;
	else
		return pResult - pstrList;
}


void Swap(char** pArr, int idx1, int idx2)
{
	char* temp = pArr[idx1];
	pArr[idx1] = pArr[idx2];
	pArr[idx2] = temp;
}

void SortString(char** pArr, int cnt)
{
	int i, j, maxldx;
	for (i = 0; i < cnt - 1; i++)
	{
		maxldx = (cnt - i) - 1;
		for (j = 0; j < (cnt - i) - 1; j++)
			if (strcmp(pArr[j], pArr[maxldx]) > 0)
				maxldx = j;
		Swap(pArr, maxldx, (cnt - i) - 1);
	}
}


int GetTotal(int(*pList)[4])
{
	int i, j, nTotal = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 4; j++)
			nTotal += pList[i][j];
	}

	return nTotal;
}


int mystrcmp(char *pList01, char *pList02)
{
	while (*pList01 != '\0')
	{
		if (tolower(*pList01) != tolower(*pList02))
		{
			return 1;
			break;
		}
		else
		{
			++pList01;
			++pList02;
		}
	}

	if (*pList02 != '\0')
		return 1;
	else
		return 0;
}