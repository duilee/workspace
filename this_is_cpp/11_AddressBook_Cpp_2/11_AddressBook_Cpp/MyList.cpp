#include "stdafx.h"
#include "MyList.h"
#include "UserData.h"
#include <cstring>
#include <conio.h>

#define DATA_FILE_NAME "Address.dat"

CMyList::CMyList(CMyNode *pHead)
{

	m_pHead = pHead;

}


CMyList::~CMyList(void)
{

	ReleaseList();
}

void CMyList::PrintAll(void)
{
	CMyNode *pTmp = m_pHead->pNext;

	while (pTmp != NULL){
		pTmp->PrintNode();
		pTmp = pTmp->pNext;
	}

	printf("CUserData Counter : %d\n", CUserData::GetUserDataCounter());

	_getch();
}

void CMyList::ReleaseList(void)
{
	CMyNode *pTmp = m_pHead;
	CMyNode *pDelete = NULL;

	while (pTmp != NULL){
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		delete pDelete;
	}

	m_pHead = NULL;
}

CMyNode* CMyList::FindNode(const char* pszKey)
{
	CMyNode *pTmp = m_pHead->pNext;
	
	while (pTmp != NULL){
		if (strcmp(pTmp->GetKey(), pszKey) == 0)
			return pTmp;

		// to next node
		pTmp = pTmp->pNext;
	}

	// if no data with desired name
	return NULL;
}

int CMyList::AddNewNode(CMyNode *pNewNode)
{

	//check if there is a node with same name
	if (FindNode(pNewNode->GetKey()) != NULL)
	{
		delete pNewNode;
		return 0;
	}
		

	//attach next to the dummy head
	// most recent node at the front
	pNewNode->pNext = m_pHead->pNext;
	m_pHead->pNext = pNewNode;

	return 1;
}

int CMyList::RemoveNode(const char* pszKey)
{
	CMyNode *pPreveNode = m_pHead;
	CMyNode *pDelete = NULL;

	while (pPreveNode->pNext != NULL){
		pDelete = pPreveNode->pNext;

		if (strcmp(pDelete->GetKey(), pszKey) == 0){
			pPreveNode->pNext = pDelete->pNext;
			delete pDelete;

			return 1;
		}

		pPreveNode = pPreveNode->pNext;
	}

	return 0;
}