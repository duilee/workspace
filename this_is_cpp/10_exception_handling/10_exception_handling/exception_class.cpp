#include "stdafx.h"
#include <iostream>
using namespace std;

class CMyException
{
public:
	// get error code and message
	CMyException(int nCode, const char *pszMsg)
	{
		m_nErrorCode = nCode;
		strcpy_s(m_szMsg, sizeof(m_szMsg), pszMsg);
	}

	int GetErrorCode() const { return m_nErrorCode; }
	const char* GetMessage() const { return m_szMsg; }

private:
	int m_nErrorCode;
	char m_szMsg[128];
};

int exception_class(void)
{
	try
	{
		int nInput = 0;
		cout << "input a positive integer: ";
		cin >> nInput;

		if (nInput < 0)
		{
			CMyException exp(10, "You must input a positive integer.");
			throw exp;
		}
	}

	catch (CMyException &exp)
	{
		cout << "Error Code [" << exp.GetErrorCode() << "] "
			<< exp.GetMessage() << endl;
	}

	return 0; 
}