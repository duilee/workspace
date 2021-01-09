#include <stdio.h>

//change a to "a" in string
#define STRING(a)	#a

//combine a and b
#define PASTER(a,b)	a##b

int macro2()
{
	int nData = 10;

	//PASTER(nDa, ta) is same as nData
	printf("%d\n", PASTER(nDa, ta));
	printf("%d\n", nData);

	//STRING(nData) is same as "nData" 
	printf("%s\n", STRING(nData));
	return 0;
}