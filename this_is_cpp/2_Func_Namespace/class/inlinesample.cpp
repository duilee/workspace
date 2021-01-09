
#include "stdafx.h"
#include <cstdio>

//macro
#define ADD(a, b)((a) + (b))

int Add_2(int a, int b)
{
	return a + b;
}

//inline
inline int AddNew(int a, int b)
{
	return a + b;
}

int samples(void)
{
	int a, b;
	scanf_s("%d%d", &a, &b);

	printf("ADD(): %d", ADD(a, b));
	printf("ADD(): %d", Add_2(a, b));
	printf("AddNew(): %d", AddNew(a, b));
	return 0;
}

