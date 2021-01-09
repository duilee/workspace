#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct USERDATA
{
	unsigned int nHeight;
	char szName[12];
	char szPhone[12];
	unsigned char sex;

	struct USERDATA *pNext;
} USERDATA;

int main(void)
{
	//two cases are the same
	
	USERDATA a;
	a.nHeight = 180;
	strcpy_s(a.szName, sizeof(a.szName), "Ho-sung");
	strcpy_s(a.szPhone, sizeof(a.szPhone), "123-1234");
	a.sex = 'M';

	char buffer[sizeof(USERDATA)];
	USERDATA *pData = (USERDATA*)buffer;
	pData->nHeight = 180;
	strcpy_s(pData->szName, sizeof(pData->szName), "David");
	strcpy_s(pData->szPhone, sizeof(pData->szPhone), "123-1234");
	pData->sex = 'M';

	a.pNext = pData;

	printf("%s", a.pNext->szName);

	return 0;
}