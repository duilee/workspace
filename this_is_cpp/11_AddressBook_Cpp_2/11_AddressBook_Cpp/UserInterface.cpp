#include "stdafx.h"
#include "UserInterface.h"
#include "MyList.h"
#include <cstring>
#include <conio.h>
#include <stdlib.h>

CUserInterface::CUserInterface(CMyList &rList)
: m_List(rList)
{
}


CUserInterface::~CUserInterface()
{
}

void CUserInterface::Add(void)
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
	m_List.AddNewNode(szName, szPhone);
}

void CUserInterface::Search(void)
{
	char szName[32] = { 0 };
	CUserData *pNode = NULL;

	printf("Input name : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName));

	pNode = m_List.FindNode(szName);
	if (pNode != NULL) {
		printf("[%p] %s\t%s [%p]\n", pNode, pNode->GetName(), pNode->GetPhone(), pNode->GetNext());
	}

	else{
		puts("Error: Can not find data");
	}

	_getch();

}

void CUserInterface::Remove(void)
{
	char szName[32] = { 0 };

	printf("Input name : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName));

	m_List.RemoveNode(szName);
}

int CUserInterface::PrintUI(void)
{
	int nInput = 0;

	system("cls");
	printf("[1] Add\t [2] Search\t [3] Print all\t [4] Remove\t [0] Exit\n:");

	//return input from user
	scanf_s("%d", &nInput);

	return nInput;
}

int CUserInterface::Run(void)
{
	int nMenu = 0;

	//main event loop
	while ((nMenu = PrintUI()) != 0)
	{
		switch (nMenu)
		{
		case 1: //Add
			Add();
			break;

		case 2: //Search
			Search();
			break;

		case 3: //Print all
			m_List.PrintAll();
			break;

		case 4: //Remove
			Remove();
			break;
		}
	}
	return nMenu;
}