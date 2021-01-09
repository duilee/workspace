// class.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

//C++ allows multiple functions with same name

//Callee
void TestFunc(int a, int b = 10)
{
	printf("a: %d, b: %d\n", a, b);
}

void TestFunc(int nParam)
{

}

//Caller
int _tmain(int argc, _TCHAR* argv[])
{
	TestFunc(3, 4);
	//TestFunc(3); gives out error
	return 0;
}

