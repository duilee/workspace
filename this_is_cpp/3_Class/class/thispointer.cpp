// class.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//////////////developer code
class CTest
{
public:
	CTest()
	{
//		cout << "CTest()" << endl;
		m_nData = 0;
	}

	~CTest()
	{
//		cout << "~CTest()" << endl;
	}

	void PrintData()
	{
		cout << this << endl;
		cout << m_nData << endl;
		cout << this->m_nData << endl;
	}
protected:
	int m_nData = 0;
};

///////////user code
int thispointer(void)
{
	// two addresses are different
	// but this pointer follows the class address
	CTest a;
	cout << &a << endl;
	a.PrintData();

	CTest b;
	cout << &b << endl;
	b.PrintData();

	return 0;
}

