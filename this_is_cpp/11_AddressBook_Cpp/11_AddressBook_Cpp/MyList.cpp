#include "stdafx.h"
#include "MyList.h"
#include <cstring>
#include <conio.h>

#define DATA_FILE_NAME "Address.dat"

CMyList::CMyList(void)
{
	FILE *fp = NULL;
	CUserData user;

	fopen_s(&fp, DATA_FILE_NAME, "rb");
	
	if (fp != NULL)
	{
		ReleaseList();

		while (fread(&user, sizeof(CUserData), 1, fp))
			AddNewNode(user.GetName(), user.GetPhone());

		fclose(fp);
	}

}


CMyList::~CMyList(void)
{
	FILE *fp = NULL;
	CUserData *pTmp = m_Head.pNext;

	fopen_s(&fp, DATA_FILE_NAME, "wb");

	if (fp == NULL) {
		puts("ERROR : couldnt open the file in write mode");
		_getch();
	}

	else
	{
		while (pTmp != NULL){
			if (fwrite(pTmp, sizeof(CUserData), 1, fp) != 1)
				printf("ERROR: fail to save data about &s.\n", pTmp->szName);

			pTmp = pTmp->pNext;
		}

		fclose(fp);
	}

	ReleaseList();
}

void CMyList::PrintAll(void)
{
	CUserData *pTmp = m_Head.pNext;

	while (pTmp != NULL){
		printf("[%p] %s\t%s [%p]\n", pTmp, pTmp->szName, pTmp->szPhone, pTmp->pNext);

		pTmp = pTmp->pNext;
	}

	printf("CUserData Counter : %d\n", CUserData::GetUserDataCounter());

	_getch();
}

void CMyList::ReleaseList(void)
{
	CUserData *pTmp = m_Head.pNext;
	CUserData *pDelete = NULL;

	while (pTmp != NULL){
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		delete pDelete;
	}

	m_Head.pNext = NULL;
}

CUserData* CMyList::FindNode(const char* pszName)
{
	CUserData *pTmp = m_Head.pNext;
	while (pTmp != NULL){
		if (strcmp(pTmp->szName, pszName) == 0)
			return pTmp;

		// to next node
		pTmp = pTmp->pNext;
	}

	// if no data with desired name
	return NULL;
}

int CMyList::AddNewNode(const char* pszName, const char* pszPhone)
{
	CUserData *pNewUser = NULL;

	//check if there is a node with same name
	if (FindNode(pszName) != NULL)
		return 0;

	//allocate memory
	pNewUser = new CUserData;

	//save data to memory
	sprintf_s(pNewUser->szName, sizeof(pNewUser->szName), "%s", pszName);
	sprintf_s(pNewUser->szPhone, sizeof(pNewUser->szPhone), "%s", pszPhone);
	pNewUser->pNext = NULL;

	//attach next to the dummy head
	// most recent node at the front
	pNewUser->pNext = m_Head.pNext;
	m_Head.pNext = pNewUser;

	return 1;
}

int CMyList::RemoveNode(const char* pszName)
{
	CUserData *pPreveNode = &m_Head;
	CUserData *pDelete = NULL;

	while (pPreveNode->pNext != NULL){
		pDelete = pPreveNode->pNext;

		if (strcmp(pDelete->szName, pszName) == 0){
			pPreveNode->pNext = pDelete->pNext;
			delete pDelete;

			return 1;
		}

		pPreveNode = pPreveNode->pNext;
	}

	return 0;
}