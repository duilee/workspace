#include <stdio.h>

// declare IP_ADDR union
typedef union _IP_ADDR
{
	int nAddress;
	short awData[2];
	unsigned char addr[4];
} IP_ADDR;

int unionfunc(void)
{
	IP_ADDR Data = { 0 };
	Data.nAddress = 0x41424344;

	// split 0x41424344 into 0x41, 0x42, 0x43, 0x44,
	// and print as character
	printf("%c%c%c%c\n", Data.addr[0], Data.addr[1],
		Data.addr[2], Data.addr[3]);
	//split into to 16 bits
	printf("%X, %d\n", Data.awData[0], Data.awData[0]);
	printf("%X, %d\n", Data.awData[1], Data.awData[1]);
	return 0;

}