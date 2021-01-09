#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct USERDATA
{
	int nAge;
	char szName[32];
	char szPhone[32];
} USERDATA;

int structarray(void)
{
	//USERDATA struct array define
	USERDATA userList[4] = {
		{10 , "kim", "1234"},
		{11, "Jung", "2345"},
		{17, "Joo", "3456"},
		{ 12, "Yong", "4567" }
	};
	int i = 0;

	for (i = 0; i < 4; ++i)
		printf("Age: %d/t%s/t%s\n", userList[i].nAge, userList[i].szName,
		userList[i].szPhone);
	return 0;

}

int structdynamic(void)
{
	// define USERDATA pointer
	USERDATA *pUser = NULL;

	// Dynamic allocation for USERDATA structure
	pUser = (USERDATA*)malloc(sizeof(USERDATA));

	// pUser->szNmae == (*pUser).szName
	//for pointer use -> to access
	pUser->nAge = 10;
	strcpy_s(pUser->szName, sizeof(pUser->szName), "Hoon");
	strcpy_s(pUser->szPhone, sizeof(pUser->szPhone), "9876");
	
	printf("Age: %d/t%s/t%s\n", pUser->nAge, pUser->szName, pUser->szPhone);

	free(pUser);
	return 0;
}