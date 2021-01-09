#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int unicode01(void)
{
	wchar_t *pwszData = L"String";
	wchar_t wszData[32];

	wcscpy(wszData, pwszData);
	wprintf(L"%s\n", wszData);

	return 0;
}

int unicode02(void)
{
	// get string in unicode
	wchar_t *pwszData = L"String";

	// string array in MBCS
	char szData[32];
	size_t nConverted = 0;

	// get length of the string after conversion to unicode
	nConverted = wcstombs(NULL, pwszData, 32);
	printf("%d\n", nConverted);
	
	return 0;
}