#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

///////////////////////////////////////////////////
// data file to save the address book
#define DATA_FILE_NAME "Address.dat"

///////////////////////////////////////////////////
void ReleaseList();

///////////////////////////////////////////////////
typedef struct _USERDATA
{
	char szName[32]; //name
	char szPhone[32]; //phone number

	struct _USERDATA *pNext;
} USERDATA;

//dummy head node
USERDATA g_Head = { 0 };

////////////////////////////////////////////////////
//function to search for a specific node 
USERDATA *FindNode(char *pszName)
{
	USERDATA *pTmp = g_Head.pNext;
	while (pTmp != NULL){
		if (strcmp(pTmp->szName, pszName) == 0)
			return pTmp;

		// to next node
		pTmp = pTmp->pNext;
	}

	// if no data with desired name
	return NULL;
}

///////////////////////////////////////////////////////
int AddNewNode(char *pszName, char *pszPhone)
{
	USERDATA *pNewUser = NULL;

	//check if there is a node with same name
	if (FindNode(pszName) != NULL)
		return 0;

	//allocate memory
	pNewUser = (USERDATA*)malloc(sizeof(USERDATA));
	memset(pNewUser, 0, sizeof(USERDATA));

	//save data to memory
	sprintf_s(pNewUser->szName, sizeof(pNewUser->szName), "%s", pszName);
	sprintf_s(pNewUser->szPhone, sizeof(pNewUser->szPhone), "%s", pszPhone);
	pNewUser->pNext = NULL;

	//attach next to the dummy head
	// most recent node at the front
	pNewUser->pNext = g_Head.pNext;
	g_Head.pNext = pNewUser;

	return 1;
}

////////////////////////////////////////////////////////////////
//get name and add to the list
void Add()
{
	char szName[32] = { 0 };
	char szPhone[32] = { 0 };

	printf("Input name : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName));

	printf("Input phone number : ");
	fflush(stdin);
	gets_s(szPhone, sizeof(szPhone));

	//add to the actual list
	AddNewNode(szName, szPhone);
}

/////////////////////////////////////////////////////////////
// search specfic node
void Search()
{
	char szName[32] = { 0 };
	USERDATA *pNode = NULL;

	printf("Input name : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName));

	pNode = FindNode(szName);
	if (pNode != NULL) {
		printf("[%p] %s\t%s [%p]\n", pNode, pNode->szName, pNode->szPhone, pNode->pNext);
	}

	else{
		puts("Error: Can not find data");
	}

	_getch();
	
}

/////////////////////////////////////////////////////////
// print all data in the list
void PrintAll()
{
	USERDATA *pTmp = g_Head.pNext;
	while (pTmp != NULL){
		printf("[%p] %s\t%s [%p]\n", pTmp, pTmp->szName, pTmp->szPhone, pTmp->pNext);

		pTmp = pTmp->pNext;
	}

	_getch();
}

///////////////////////////////////////////////////////
//search specific node and delete
int RemoveNode(char *pszName)
{
	USERDATA *pPreveNode = &g_Head;
	USERDATA *pDelete = NULL;

	while (pPreveNode->pNext != NULL){
		pDelete = pPreveNode->pNext;

		if (strcmp(pDelete->szName, pszName) == 0){
			pPreveNode->pNext = pDelete->pNext;
			free(pDelete);

			return 1;
		}

		pPreveNode = pPreveNode->pNext;
	}

	return 0;
}

///////////////////////////////////////////////////////
//remove data by getting the name
void Remove()
{
	char szName[32] = { 0 };

	printf("Input name : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName));

	RemoveNode(szName);
}

//////////////////////////////////////////////////////
//function to print UI
int PrintUI()
{
	int nInput = 0;

	system("cls");
	printf("[1] Add\t [2] Search\t [3] Print all\t [4] Remove\t [0] Exit\n:");

	//return input from user
	scanf_s("%d", &nInput);

	return nInput;
}

///////////////////////////////////////////////////////
// read nodes from data file and complete list 
int LoadList(char *pszFileName)
{
	FILE *fp = NULL;
	USERDATA user = { 0 };

	fopen_s(&fp, pszFileName, "rb");

	if (fp == NULL)
		return 0;

	ReleaseList();

	while (fread(&user, sizeof(USERDATA), 1, fp))
		AddNewNode(user.szName, user.szPhone);

	fclose(fp);

	return 0;
}

////////////////////////////////////////////////////////////
//function to save data in the file
int SaveList(char *pszFileName)
{
	FILE *fp = NULL;
	USERDATA *pTmp = g_Head.pNext;

	fopen_s(&fp, pszFileName, "wb");

	if (fp == NULL) {
		puts("ERROR : couldnt open the file in write mode");
		_getch();

		return 0;
	}

	while (pTmp != NULL){
		if (fwrite(pTmp, sizeof(USERDATA), 1, fp) != 1)
			printf("ERROR: fail to save data about &s.\n", pTmp->szName);

		pTmp = pTmp->pNext;
	}

	fclose(fp);

	return 1;
}

///////////////////////////////////////////////////////////////////
// delete all data from list
void ReleaseList()
{
	USERDATA *pTmp = g_Head.pNext;
	USERDATA *pDelete = NULL;

	while (pTmp != NULL){
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		free(pDelete);
	}

	memset(&g_Head, 0, sizeof(USERDATA));
}

//////////////////////////////////////////////////////////////////
void main()
{
	int nMenu = 0;
	LoadList(DATA_FILE_NAME);

	//main event loop
	while ((nMenu = PrintUI()) != 0) {
		switch (nMenu) {
		case 1: //Add
			Add();
			break;
			
		case 2: //Search
			Search();
			break;

		case 3: //Print all
			PrintAll();
			break;

		case 4: //Remove
			Remove();
			break;
		}
	}

	//save file before quiting
	SaveList(DATA_FILE_NAME);
	ReleaseList();
}