// HelloCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	//C
	printf("Hello, World");
	//C++
	std::cout << "Hello, World" << std::endl;

	char szName[32];
	std::cout << "Enter your name" << std::endl;
	std::cin >> szName;

	variable();

	return 0;
}

