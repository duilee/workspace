#include <stdio.h>

#include <float.h>

int main(void)
{
	char ch = 'A';
	wchar_t wch = L'A';
	short sData = 10;
	int nData = 10;
	long lData = 10L;
	long int lnData = 10L;
	long long int llnData = 10LL;

	unsigned char byNewData = 0;
	unsigned short sNewData = 65535U;
	unsigned int uNewData = 1U;
	unsigned long int ulNewData = 1UL;
	unsigned long long int ullNewData = 1ULL;

	123.0;		//double;
	123.0F;		//float;
	printf("%f\n", 2147483648.0F);
	printf("%f\n", 2147483648.0F - 50);
	printf("%f\n", 2147483648.0F - 64);
	printf("%f\n", 2147483648.0F - 65);
	/*
	float innately carries error, counts until 6 dec digits
	instead use double for more accuracy 15 dec digits
	*/

	// double range;
	double dData = 123.456;
		printf("%f\n", dData);
		printf("%E - %E\n", DBL_MIN, DBL_MAX);

	// string
	// F9 to select the line, then F5 to debug and see memory
	char ch1 = 'A', ch2 = 'B', ch3 = 'C';
	char szData[4] = {'A', 'B', 'C'};
	char szNewData[4] = {"ABC"};

	return 0;

}