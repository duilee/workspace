#include <stdio.h>

typedef struct USERDATA
{
	char szName[32];
	char szPhone[32];

	struct USERDATA *pNext;
} USERDATA;

int structnode(void)
{
	// create for USERDATA structures
	USERDATA userList[4] = {
		{ "kim", "1234", NULL },
		{ "jung", "2345", NULL },
		{ "joo", "3456", NULL },
		{ "yong", "4567", NULL }
	};
	// point to save first instance of the linked list
	USERDATA *pUser = NULL;

	userList[0].pNext = &userList[1];
	userList[1].pNext = &userList[2];
	userList[2].pNext = &userList[3];

	// End of Linked list
	userList[3].pNext = NULL;

	pUser = &userList[0];
	while (pUser != NULL)
	{
		printf("%s, %s\n", pUser->szName, pUser->szPhone);
		pUser = pUser->pNext;
	}
	return 0;

}

