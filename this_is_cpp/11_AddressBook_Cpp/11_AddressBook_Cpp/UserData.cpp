#include "stdafx.h"
#include "UserData.h"
#include <cstring>
using namespace std;

int CUserData::nUserDataCounter = 0;

CUserData::CUserData(void)
:pNext(NULL)
{
	memset(szName, 0, sizeof(szName));
	memset(szPhone, 0, sizeof(szPhone));

	nUserDataCounter++;
}


CUserData::~CUserData(void)
{
	nUserDataCounter--;
}
