// 9_template.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// can also define template as template<typename T, int nSize>
// this case, change m_nSize to nSize
template<typename T>
class CMyArray
{
public:
	explicit CMyArray(int nSize) : m_nSize(nSize)
	{
		m_pData = new T[nSize];
	}

	~CMyArray() { delete[] m_pData; }

	//copy constructor
	CMyArray(const CMyArray &rhs)
	{
		m_pData = new T[rhs.m_nSize];
		memcpy(m_pData, rhs.m_pData, sizeof(T)*rhs.m_nSize);
		m_nSize = rhs.m_nSize;
	}
	
	// = operator
	CMyArray& operator=(const CMyArray &rhs)
	{
		if (this == &rhs)
			return *this;

		delete m_pData;
		m_pData = new T[rhs.m_nSize];
		memcpy(m_pData, rhs.m_pData, sizeof(T)*rhs.m_nSize);
		m_nSize = rhs.m_nSize;

		return *this;
	}

	//move constructor
	CMyArray(CMyArray &&rhs)
	{
		operator = (rhs);
	}

	CMyArray& operator=(const CMyArray &&rhs)
	{
		m_pData = rhs.m_pData;
		m_nSize = rhs.m_nSize;
		rhs.m_pData = nullptr;
		rhs.m_nSize = 0;
	}

	// array operator
	T& operator[](int nIndex)
	{
		if (nIndex < 0 || nIndex >= m_nSize)
		{
			cout << "Error: index out of range" << endl;
			exit(1);
		}

		return m_pData[nIndex];
	}

	//const array operator
	T& operator[](int nIndex) const
	{
		return operator[](nIndex);
	}

	//return array size
	int GetSize() { return m_nSize; }

private:
	T *m_pData = nullptr;
	int m_nSize = 0;
};


int _tmain(int argc, _TCHAR* argv[])
{
	// int array
	CMyArray<int> arr(5);

	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40;
	arr[4] = 50;

	for (int i = 0; i < 5; ++i)
		cout << arr[i] << ' ';

	cout << endl;

	CMyArray<int> arr2(3);
	arr2 = arr;
	for (int i = 0; i < 5; ++i)
		cout << arr[i] << ' ';

	cout << endl;

	return 0;
}

