#pragma once
#include "MyNode.h"

class CUserData : public CMyNode
{
public:
	CUserData(void);
	CUserData(const char* pszName, const char* pszPhone);
	~CUserData(void);

	const char* GetName(void) const { return szName; }
	const char* GetPhone(void) const { return szPhone; }
	static int GetUserDataCounter(void) { return nUserDataCounter; }

protected:
	char szName[32]; //name
	char szPhone[32]; //phone number

	static int nUserDataCounter;
public:
	virtual const char* GetKey(void);
	virtual void PrintNode(void);
};

