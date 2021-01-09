#include "stdafx.h"
#include <iostream>
using namespace std;

class CTest
{
public:
	CTest() // Default
	{
		cout << "CTest()" << endl; 
		m_pData = new int(5);
	}

	explicit CTest(int nParam) //conversion constructor
	{
		cout << "CTest(int)" << endl;
		m_pData = new int(nParam);
	}

	CTest(const CTest &rhs) //Copy constructor
	{
		cout << "CTest(const CTest &)" << endl; 
	//	this->m_nData = rhs.m_nData;  // copy member value
		this->m_pData = new int(*rhs.m_pData);
	}
	~CTest() { 
		cout << "~CTest()" << endl;
		delete m_pData;
	}

	void SetData(int nParam)
	{
		*m_pData = nParam;
	}

	int GetData() const
	{
		return *m_pData;
	}

	// define operator for class
	CTest& operator =(const CTest &rhs)
	{
		// default is m_pData = rhs.m_pData;  //shallow
		*m_pData = *rhs.m_pData; // deep
		return *this;
	}

private:
	int *m_pData = nullptr;	//C++11
};

void TestFunc(const CTest &param)
{
	cout << param.GetData() << endl;
}

int deep_shallow_ccopy(void)
{

	//int *pA = new int(5);
	//int *pB = NULL;

	//pB = pA;   //Shallow

	//pB = new int(*pA); //Deep

	//cout << *pA << endl;
	//cout << *pB << endl;

	//delete pA;
	//delete pB;

	CTest a;
//	CTest b(a);  // copy constructor
//  CTest b(10); //conversion constructor
	CTest b;

	// gives out error, if two pointers are shallow copies
	// use copy constructor to make a deep copy

	a.SetData(5);
	//b = a;
	b.operator=(a);

	cout << a.GetData() << endl;
	cout << b.GetData() << endl;

	// TestFunc(CTest(5)) is same as TestFunc(5)

	return 0;
}
