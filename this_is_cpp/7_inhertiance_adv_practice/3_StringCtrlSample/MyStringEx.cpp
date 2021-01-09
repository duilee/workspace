#include "stdafx.h"
#include "MyStringEx.h"


CMyStringEx::CMyStringEx()
{
}


CMyStringEx::~CMyStringEx()
{
}

int CMyStringEx::SetString(const char* pszParam)
{
	int nResult;

	if (strcmp(pszParam, "bastard") == 0)
		nResult = CMyString::SetString("nice person");

	else
		nResult = CMyString::SetString(pszParam);

	return nResult;

}

int CMyStringEx::Find(const char* pszParam)
{
	if (pszParam == NULL || GetString() == NULL)
		return -1;
	
	const char *pChar = nullptr;
	pChar = strstr(GetString(), pszParam);

	if (pChar != NULL)
		return pChar - GetString();

	return -1;
}

CMyStringEx::CMyStringEx(const char *pszParam):CMyString(pszParam) {}

void CMyStringEx::OnSetString(char* pszData, int nLength)
{
	if (strcmp(pszData, "bastard") == 0)
		strcpy_s(pszData, sizeof(char)*(nLength + 1), "*nice person*");
}