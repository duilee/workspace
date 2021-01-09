#include "stdafx.h"
#include <iostream>
using namespace std;

class CTest
{
public:
	CTest(int nParam) : m_nData(nParam) { m_nCount++; }
	int GetData() { return m_nData; }
	void ResetCount() { m_nCount = 0; }

	//static method
	static int GetCount()
	{
		return m_nCount;
	};

private:
	int m_nData;

	static int m_nCount;
};

// CTEST class static member variable define
int CTest::m_nCount = 0;

int static_variable(void)
{
	CTest a(5), b(10);

	//access static member
	cout << CTest::GetCount() << endl;

	return 0;
}