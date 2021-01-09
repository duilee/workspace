// class.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

//////////////developer code
class USERDATA
{
public:	
	int nAge;
	char szName[32];

	void Print(USERDATA *pUser)
	{
		printf("%d, %s\n", pUser->nAge, pUser->szName);
	}

	void Print2()
	{
		//actually printf("%d, %s\n",this->nAge, this->szName);
		printf("%d, %s\n", nAge, szName);
	}
};

///////////user code
int _tmain(int argc, _TCHAR* argv[])
{
	USERDATA a = { 20, "Hong"};

	//print
	//1
	//printf("%d, %s\n", a.nAge, a.szName);
	//2
	//PrintUserData(&a);
	//3
	//a.Print(&a);
	//4
	//a.Print2();        //C++

	thispointer();
	return 0;
}

