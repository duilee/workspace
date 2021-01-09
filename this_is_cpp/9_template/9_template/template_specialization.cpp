#include "stdafx.h"
#include <memory>
#include <iostream>
using namespace std;

template<typename T>
T Add(T a, T b) { return a + b; }

// if both variables are char*
template< >
char* Add(char *pszLeft, char *pszRight)
{
	int nLenLeft = strlen(pszLeft);
	int nLenRight = strlen(pszRight);
	char *pszResult = new char[nLenLeft + nLenRight + 1];

	//copy to new memory
	strcpy_s(pszResult, nLenLeft + 1, pszLeft);
	strcpy_s(pszResult + nLenLeft, nLenRight + 1, pszRight);

	return pszResult;
}

int temp_special(void)
{
	int nResult = Add<int>(3, 4);
	cout << nResult << endl;

	char *pszResult = Add<char*>("Hello", "World");
	cout << pszResult << endl;
	delete[] pszResult;

	return 0;
}