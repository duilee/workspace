# include <stdio.h>

int getstry(void)
{

// to run click f10 to run seperate lines
	FILE *fp = stdin;
	int nAge = 0;
	printf("insert your age: ");
	//use scanf_s to get integer input in int format
	scanf_s("%d", &nAge);

	// to prevent next gets_s() from taking \n, need to erase buffer
	// to do so, use get char() or simply fflush(stdin)
	// or also can use scanf_s("%d%*c", &nAge")
	// getchar();
	fflush(stdin);

	char szName[12] = {0};
	printf("insert your name: ");
	// gets_s() instead of gets() for more secure environment
	gets_s(szName, sizeof(szName));

	printf("%d, %s\n", nAge, szName);
	return 0;



}