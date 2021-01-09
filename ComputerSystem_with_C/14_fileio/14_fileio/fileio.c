#include <stdio.h>
#include <string.h>

void filefscanf(void)
{
	int nData = 0;
	char szBuffer[128] = { 0 };
	FILE *fp = NULL;

	fp = fopen("fscanfTest.txt", "w");
	fprintf(fp, "%d,%s\n", 20, "Test");
	fclose(fp);

	//open file again and get saved text
	fp = fopen("fscanfTest.txt", "r");
	fscanf(fp, "%d,%s", &nData, szBuffer);
	fclose(fp);

	//print read text
	printf("%d, %s\n", nData, szBuffer);
}

void filefgetc(void)
{
	FILE *fp = NULL;
	char szBuffer[512] = { 0 };

	// create file and add multiple lines of string
	fp = fopen("Test.txt", "w");
	fputs("Test\n", fp);
	fputs("String\n", fp);
	fputs("Data\n", fp);
	fclose(fp);

	//reopen test.txt
	fp = fopen("Test.txt", "r");
	if (fp == NULL)
		return;

	// get one line at a time
	while (fgets(szBuffer, sizeof(szBuffer), fp))
	{
		printf("%s", szBuffer);
		memset(szBuffer, 0, sizeof(szBuffer));
	}

	fclose(fp);
}

void filefflush(void)
{
	FILE *fp = stdin;
	printf("Input string: ");

	// get first character of input string
	printf("getchar( ) - %c\n", getchar());
	
	// get number of characters left in buffer
	printf("[%d] %s", fp->_cnt, fp->_base);
	printf("READ: %d\n", fp->_ptr - fp->_base);

	// get one more character 
	printf("\n\ngetchar( ) - %c\n", getchar());
	printf("[%d] %s", fp->_cnt, fp->_base);
	printf("READ: %d\n", fp->_ptr - fp->_base);

	//flush fileio buffer
	fflush(fp);
	printf("\n\nAfter flushing\n[%d] %s",
		fp->_cnt, fp->_base);
	printf("READ: %d\n", fp->_ptr - fp->_base);
}

void main(void)
{
	//filefscanf();
	//filefgetc();
	//stdinfile();
	//textfile01();
	//copyfile();
}