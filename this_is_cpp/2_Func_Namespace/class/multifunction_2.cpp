
#include "stdafx.h"
#include <iostream>

//must declare the functions first
int Add(int a, int b);
double Add(double a, double b);

int multifunction_2(void)
{
	Add(3, 4);
	Add(3.3, 4.4);
	return 0;
}

int Add(int a, int b)
{
	return a + b;
}

double Add(double a, double b)
{
	return a + b;
}
