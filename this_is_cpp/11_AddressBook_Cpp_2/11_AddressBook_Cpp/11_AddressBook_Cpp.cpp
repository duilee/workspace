// 11_AddressBook_Cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "UserInterface.h"
#include "MyList.h"
#include "UserData.h"


int _tmain(int argc, _TCHAR* argv[])
{
	CMyList DB(new CUserData);
	CUserInterface UI(DB);
	UI.Run();

	return 0;
}

