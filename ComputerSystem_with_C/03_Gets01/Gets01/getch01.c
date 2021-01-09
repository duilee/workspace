# include <stdio.h>

// another header file to use _getch()
#include <conio.h>

int getchtry(void)
{
	char ch = 0;
	// message to transfer
	printf("press any key to continue. \n");
	// get a input from user and _getch() saves it to ch
	ch = _getch();
	
	printf("Entered key is");
	putchar(ch);

	return 0;
}