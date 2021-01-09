#include "stdafx.h"
#include "MyStringEx.h"


CMyStringEx::CMyStringEx()
{
}


CMyStringEx::~CMyStringEx()
{
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
