#include <stdio.h>

#define ADD(a,b)	(a+b)
#define ERROR_MSG(msg)	printf("ERROR: %s\n", msg)

int macro1(void)
{
	printf("%d\n", ADD(3, 4));
	printf("%d\n", ADD(3, 4)*2);
	ERROR_MSG("Failed to open file!");
	return 0;

}
