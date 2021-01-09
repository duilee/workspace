// 10_exception_handling.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void ExceptTest1()
{
	int nInput;
	cout << "Input an integer between 1~10 : ";
	cin >> nInput;

	//throw exception if out of range
	if (nInput < 1 || nInput > 10)
		throw nInput;
}

void ExceptTest2()
{
	char ch;
	cout << "Menu: [A]dd\t[D]elete\t[E]xit\n";
	cin >> ch;

	// throw exception if input is not in the rror
	if (ch != 'A' && ch != 'D' && ch != 'E')
		throw ch;
}


int _tmain(int argc, _TCHAR* argv[])
{
	cout << "****Begin****" << endl;
	try
	{
		// easier structural flow within the block
		ExceptTest1();
		ExceptTest2();
	}

	// can separate exception handling depending on the type
	catch (int nExp)
	{
		cout << "Error:" << nExp << "is a number out of range" << endl;
	}

	catch (char ch)
	{
		cout << "Error:" << ch << "Unknown menu." << endl;
	}

	cout << "****End****" << endl;

	return 0;
}

