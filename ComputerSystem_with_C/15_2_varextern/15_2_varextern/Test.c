// Test.c file
#include <stdio.h>

int g_nCounter = 0;

void InitCounter(int nData)
{
	g_nCounter = nData;
}

void IncreaseCounter()
{
	g_nCounter++;
}