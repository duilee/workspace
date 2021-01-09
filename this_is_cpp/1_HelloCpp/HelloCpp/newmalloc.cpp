#include "stdafx.h"
#include <iostream>


int newmalloc(void)
{
	int nNewData = 20;
	//C
	int *pnData = (int*)malloc(sizeof(int) * 5);
	free(pnData);

	//C++
	int *pnNewData = new int[5];
	delete [] pnNewData;


	return 0;
}