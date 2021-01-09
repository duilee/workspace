#include <stdio.h>

int arrayofptr01(void)
{
	char *astrList[3] = { "Hello", "World", "String" };

	// %s takes char*, %c takes char
	printf("%s\n", astrList[0]);
	printf("%s\n", astrList[1]);
	printf("%s\n", astrList[2]);

	// astrList[0] has an address of string array, get relative address
	printf("%s\n", astrList[0] + 1);
	printf("%s\n", astrList[1] + 2);
	printf("%s\n", astrList[2] + 3);

	//char* is logically same is 2D array
	printf("%c\n", astrList[0][3]);
	printf("%c\n", astrList[1][3]);
	printf("%c\n", astrList[2][3]);
	return 0;
}

int arrayofptr02(void)
{
	char* astrList[3] = { "Hello", "World", "String" };
	// assign variable with char** element
	char* *ppstrList = astrList;
	// assign variable with char*** element
	char** *pppstrList = &ppstrList;

	//*(char ** + index) returns char*
	// hence use %s or puts
	puts(ppstrList[0]);
	puts(ppstrList[1]);
	puts(ppstrList[2]);

	//**(char ***) = char *
	puts(*pppstrList[0]);
	puts(*(*(pppstrList + 0) + 1));
	return 0;

}

int ptrtoarray01(void)
{
	char astrList[2][12] = { "Hello", "World" };
// char* *pstrList = astrList; this is wrong, element of astrList is char
	char(*pstrList)[12] = astrList;

	puts(pstrList[0]);
	puts(pstrList[1]);
	return 0;
}