// 3_StringCtrlSample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyString.h"
#include "MyStringEx.h" // CMyStringEx class header

void TestFunc(const CMyString &strParam)
{
	cout << strParam[0] << endl;
	cout << strParam[strParam.GetLength() - 1] << endl;
}

CMyString TestFunc(void)
{
	CMyString strTest("TestFunc() return");
	cout << strTest << endl;

	return strTest;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CMyStringEx strTest;
	strTest.SetString("bastard");
	cout << strTest << endl;

	return 0;
}

