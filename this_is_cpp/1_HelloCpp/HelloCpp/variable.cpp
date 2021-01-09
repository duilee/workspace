#include "stdafx.h"
#include <iostream>


int variable(void)
{
	//declare and define
	int a = 10;   //C style
	int b(10);	  //C++ style

	int c(10);
	auto d(c); //auto follows the type of input
	int(10);
	std::cout << d << std::endl;


	return 0;
}