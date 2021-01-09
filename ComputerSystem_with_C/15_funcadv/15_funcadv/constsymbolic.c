#include <stdio.h>

// Define MAXLENGTH constant
// be aware that no ';' after
#define MAXLENGTH 32

int constsymbolic()
{
	char szName[MAXLENGTH] = { 0 };

	printf("ENTER YOUR NAME : ");
	gets_s(szName, sizeof(char)* MAXLENGTH);
	return 0;
}