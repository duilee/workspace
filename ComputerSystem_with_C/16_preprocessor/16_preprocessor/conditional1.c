#include <stdio.h>

//condition on whether _MSGTEST_ is defined
#ifdef _MSGTEST_
#define MYMESSAGE	"I am a boy."
#else
#define MYMESSAGE	"You are a girl."
#endif

int conditional1(void)
{
	puts(MYMESSAGE);
	return 0;
}