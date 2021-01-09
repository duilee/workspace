# include <stdio.h>

int getchartry(void)
{
	// try using getchar and putchar
	char ch = 0;
	ch = getchar();
	putchar(ch);
	putchar('X');

	return 0;
}