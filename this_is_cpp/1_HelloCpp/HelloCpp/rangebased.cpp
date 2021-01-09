#include "stdafx.h"
#include <iostream>


int rangebased(void)
{
	// C, if list length change, for loop should also change
	int aList[5] = { 40, 30, 10, 20, 50 };

	for (int i = 0; i < 5; ++i)
		printf("d/t", aList[i]);

	// C++
	for (auto n : aList)
		printf("d/t", n);

	//to access a List
	// for (auto &n : aList)


	return 0;
}