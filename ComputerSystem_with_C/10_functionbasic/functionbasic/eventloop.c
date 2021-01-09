#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int PrintMenu(void)
{
	int nInput = 0;

	// clear screen
	system("cls");
	//print menu
	printf("[1]New\t[2]Search\t[3]Print\t[4]Remove\t[0]Exit\n");
	scanf_s("%d", &nInput);

	//return menu input
	return nInput;
}

int eventloop(void)
{
	int nMenu = 0;

	//menu event loop
	// end if 0
	while ((nMenu = PrintMenu( )) != 0)
	{
		switch (nMenu)
		{
		case 1: // New
			puts("adding new item");
			break;

		case 2: // Search
			puts("Searching with in existing item");
			break;

		case 3: // Print
			puts("print all item");
			break;

		case 4: // Remove
			puts("erase existing item");
			break;

		default: //???
			puts("unknown input");
		}

		_getch( );
	}

	puts("Bye~!");
	return 0;
}