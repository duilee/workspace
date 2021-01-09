#include <stdio.h>

int opbitandmask(void)
{
	int nData = 0x11223344;

	printf("%08X\n", nData & 0x00FFFF00);
	printf("%08X\n", nData | 0x2211FFFF);
	// ^ is exclusive OR
	printf("%08X\n", nData ^ 0x2211FFFF);
	printf("%08X\n", ~nData);
	printf("%08X\n", nData >> 8);
	printf("%08X\n", nData << 16);


	// masking will take only the desired data

	printf("%08X\n", nData & 0xFFFF0000);
	printf("%08X\n", nData & 0x00FFFF00);
	printf("%08X\n", nData & 0x0000FFFF);
	printf("%08X\n", nData & 0xFF0000FF);

	return 0;
}