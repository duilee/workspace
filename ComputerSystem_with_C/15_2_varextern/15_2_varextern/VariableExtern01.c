//VariableExtern01.c file

#include <stdio.h>

//declare functions in external source
void InitCounter(int nData);
void IncreaseCounter();

//get global variable in external source
extern int g_nCounter;

void main(void)
{
	InitCounter(10);
	printf("%d\n", g_nCounter);
	IncreaseCounter();
	printf("%d\n", g_nCounter);
}