// 5_class_operator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData()
	{
		cout << "CMyData()" << endl;
	}

	CMyData(int nParam)
		:m_nData(nParam)
	{
		cout << "CMyData(int)" << endl;
	}

	CMyData(const CMyData &rhs)
	{
		cout << "CMyData(const CMyData &)" << endl;
	}

	CMyData(const CMyData &&rhs) // moving constructor
	{
		cout << "CMyData(const CMyData &&rhs)" << endl;
	}

	~CMyData()
	{
	}

	int GetData() const
	{
		return m_nData;
	}

	void SetData(int nParam)
	{
		m_nData = nParam;
	}

	/////////////////////////////////////////////////
/*	//allowed casting
	operator int(void)
	{
		return m_nData;
	}
*/
	CMyData& operator+(CMyData &rhs)
	{
		return CMyData(this->m_nData + rhs.m_nData);
	}
	CMyData& operator=(const CMyData &rhs)
	{
//		m_nData = nParam; // not a good code
		SetData(rhs.GetData());
		return *this;
	}
	////////////////////////////////////////////////

private:
	int m_nData = 0;
};


int _tmain(int argc, _TCHAR* argv[])
{
	CMyData a;
	CMyData b;
	CMyData c;

	//a.SetData(5);
	//a.operator=(5);  '=' is a function in nature
	a = 5;
	// if return void, a = b = 5; error
	// //F5 debug and  F11 to step into
	b.SetData(6);

//	// a.getdata() + b.getdata();
//	cout << a + b << endl;

	c = a + b;
	
	return 0;

}

