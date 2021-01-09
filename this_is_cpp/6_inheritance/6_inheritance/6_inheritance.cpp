// 6_inheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CTest
{
public:
	CTest()
	{
		cout << "CTest()" << endl;
	}

	void TestFunc(void)
	{
		cout << "CTest::TestFunc()" << endl;
	}
};

class CTestEx : public CTest
{
public:
	CTestEx()
	{
		cout << "CTest()" << endl;
	}

	//redefine
	void TestFunc(void)
	{
		cout << "CTestEx::TestFunc()" << endl;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	CTestEx a;
	CTest &b = a;
	b.TestFunc();
	return 0;
}