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
	/*
	CMyString strData, strTest;
	strData.SetString("Hello");
	strTest.SetString("World");

	// copy constructor
	CMyString strNewData(strData);
	cout << strNewData.GetString() << endl;

	//=operator
	strNewData = strTest;
	cout << strNewData.GetString() << endl;

	TestFunc(strData);
	::TestFunc(CMyString("World"));

	// temporary object with no name
	TestFunc();
	
	CMyString strResult;
	strResult = strData + strTest;
	cout << strResult << endl;

	strData += CMyString("World");
	cout << strData << endl;
	
	CMyString strParam("HelloWorld");
	cout << strParam << endl;
	TestFunc(strParam);

	CMyString strLeft("Test"), strRight("String");

	if (strLeft == strRight)
		cout << "Same" << endl;
	else
		cout << "Different" << endl;

	strLeft = CMyString("String");

	if (strLeft != strRight)
		cout << "Same" << endl;
	else
		cout << "Different" << endl;
	*/

	CMyStringEx strTest;
	strTest.SetString("I am a boy.");
	cout << strTest << endl;

	int nIndex = strTest.Find("am");
	cout << "Index:" << nIndex << endl;

	strTest.SetString("bastard");
	cout << strTest << endl;

	strTest.SetString("Hello");
	cout << strTest << endl;

	CMyStringEx strLeft("Hello"), strRight("World");
	cout << strLeft + strRight << endl;

	return 0;
}

