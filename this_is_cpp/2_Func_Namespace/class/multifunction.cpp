
#include "stdafx.h"
#include <iostream>


//int Add(int a, int b)
//{
//	return a + b;
//}
//
//double Add(double a, double b)
//{
//	return a + b;
//}

template <typename T>
T Add(T a, T b)
{
	return a + b;
}

int multifunction(void)
{
	std::cout << Add(3, 4) << std::endl;
	std::cout << Add(3.3, 4.4) << std::endl;
	return 0;
}

