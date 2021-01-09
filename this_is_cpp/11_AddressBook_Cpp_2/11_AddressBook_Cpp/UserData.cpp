#include "stdafx.h"
#include "UserData.h"
#include <cstring>
using namespace std;

int CUserData::nUserDataCounter = 0;

CUserData::CUserData(void)
{
	memset(szName, 0, sizeof(szName));
	memset(szPhone, 0, sizeof(szPhone));

	nUserDataCounter++;
}

CUserData::CUserData(const char* pszName, const char* pszPhone)
{
	memset(szName, 0, sizeof(szName));
	memset(szPhone, 0, sizeof(szPhone));

	strcpy_s(szName, sizeof(szName), pszName);
	strcpy_s(szPhone, sizeof(szPhone), pszPhone);

	nUserDataCounter++;
}


CUserData::~CUserData(void)
{
	nUserDataCounter--;
}

const char* CUserData::GetKey(void)
{
	return szName;
}

void CUserData::PrintNode(void)
{
#ifdef _DEBUG
	printf("[%p] %s\t%s [%p]\n", this, szName, szPhone, GetNext());
#else
	printf("%s\t%s\n", szName, szPhone);
#endif
}