#include "LibTest.h"
#include <stdio.h>
#include <stdarg.h>


//variableparameter function
int GetMax(int nCount, ...)
{
	int nMax = -9999, nParam = 0, i = 0;
	va_list pList = NULL;

	va_start(pList, nCount);
	for (i = 0; i < nCount; ++i)
	{
		nParam = va_arg(pList, int);
		if (nParam > nMax) nMax = nParam;
	}

	va_end(pList);
	return nMax;
}


int main(void)
{
	PrintData(10);
	PrintString("Test String");
	
	printf("MAX: %d\n", GetMax(3, 10, 30, 20));
	return 0;
}