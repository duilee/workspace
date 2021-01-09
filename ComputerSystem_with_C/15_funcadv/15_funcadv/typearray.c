#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// i.e. movements of a character
typedef enum ACTION {
	MOVE	= 100,
	MOVE_EX	= 110,
	JUMP	= 200,
	ATTACK	= 300
} ACTION;

int typearray(void)
{
	ACTION act = MOVE;
	printf("%d\n", act);

	return 0;
}