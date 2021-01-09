#include <stdio.h>
#include <string.h>

void stdinfile(void)
{
	char Buffer[128] = { 0 };
	fgets(Buffer, sizeof(Buffer), stdin);
	fputs(Buffer, stdout);
	return 0;
}

void textfile01(void)
{
	FILE *fp = NULL;
	char Buffer[128] = { 0 };
	
	gets(Buffer, sizeof(Buffer));

	fp = fopen("TestFile.txt", "a");
	fputs(Buffer, fp);
	fclose(fp);

	system("notepad.exe TestFile.txt");

}

void copyfile(void)
{
	FILE *fpSrc, *fpDst = NULL;
	char szBuffer[512] = { 0 };

	fpSrc = fopen("TestFile.txt", "r");
	fpDst = fopen("DstFile.txt", "w");
	if (fpSrc == NULL || fpDst == NULL)
		return;

	while (fgets(szBuffer, sizeof(szBuffer), fpSrc))
	{
		fputs(szBuffer, fpDst);
	}

	_fcloseall();
	system("notepad.exe DstFile.txt");


}


void binarycopy(char *Src, char *Dst)
{
	//receives directory address of two files
	// and make binary copy
	FILE *fpSrc = NULL;
	FILE *fpDst = NULL;
	size_t fileSize = 0;
	char szBuffer[4096] = { 0 };

	fopen_s(&fpSrc, Src, "rb");
	if (fpSrc == NULL)
		return;

	fseek(fpSrc, 0, SEEK_END);
	fileSize = ftell(fpSrc);
	if (fileSize > 100 * 1024 * 1024) {
		puts("File exceeds 100MB");
		return;
	}
	fseek(fpSrc, 0, SEEK_SET);

	fopen_s(&fpDst, Dst, "wb");
	if (fpDst == NULL)
		return;

	for (int i = 0; i < fileSize / 4096; ++i) {
		fread(szBuffer, 4096, 1, fpSrc);
		fwrite(szBuffer, 4096, 1, fpDst);
		printf("\b\b\b\b%3.0f%%\n", (double)100 * (4096 * i) / fileSize);
	}

	fread(szBuffer, fileSize % 4096, 1, fpSrc);
	fwrite(szBuffer, 4096, 1, fpDst);
	printf("\b\b\b\b100%%\n");

}