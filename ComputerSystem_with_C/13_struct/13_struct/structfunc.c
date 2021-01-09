#include <stdio.h>

typedef struct USERDATA
{
	int nAge;
	char szName[32];
	char szPhone[32];
} USERDATA;

// for structure used as parameter for a func, 
// use pointer for efficiency

void GetUserData(USERDATA *pUser)
{
	scanf_s("%d%*c", &pUser->nAge);
	gets_s(pUser->szName, sizeof(pUser->szName));
	gets_s(pUser->szPhone, sizeof(pUser->szPhone));
}

int structfunc(void)
{
	USERDATA user = { 0 };

	//call by reference
	GetUserData(&user);
	printf("Age: %d/t%s/t%s\n", user.nAge, user.szName, user.szPhone);
	return 0;
}

