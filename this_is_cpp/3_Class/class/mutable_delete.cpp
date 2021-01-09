#include "stdafx.h"
#include <iostream>
using namespace std;

//developer code

class CMyData
{
public:
	//initialize when called
	CMyData() : m_nData(0) { };

	int GetData(void) { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

	//use delete to prevent double data type
	void SetData(double dParam) = delete;

private:
	//set mutable to change private variables
	mutable int m_nData;
};

//user code
int usingdelete(void)
{
	CMyData a;

	//CMyData::SetData(int) method call
	a.SetData(10);
	cout << a.GetData() << endl;

	CMyData b;

	//CMyData::SetData(double) called
	//this will give out error
	b.SetData(5.5);
	cout << b.GetData() << endl;

	return 0;
}