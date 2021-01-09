#include <stdio.h>

#ifdef _DEBUG
#define MODEMESSAGE "Debug mode"
#else
#define MODEMESSAGE "Release mode"
#endif

int checkmode(void)
{
	puts(MODEMESSAGE);
	return 0;
}