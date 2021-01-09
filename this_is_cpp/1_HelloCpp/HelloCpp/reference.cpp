#include "stdafx.h"
#include <iostream>
using namespace std;


void Swap(int &a, int &b)
{
	int nTmp = a;
	a = b;
	b = nTmp;
}

int reference(void)
{
	//by reference, you can change the original variables
	int x = 10, y = 20;
	Swap(x, y);

	cout << "x: " << x << endl;
	cout << "y: " << y << endl;



	//reference
	int nData(10);
	std::cout << nData << std::endl;

	//reference is a nickname
	int &rData = nData;

	rData = 5;
	std::cout << nData << std::endl;
	//nData and rData are the same! 
	std::cout << &nData << std::endl;
	std::cout << &rData << std::endl;

	/*

	//in C
	//pointer is a varaible
	int *pnData = &nData;
	//nData = 5
	*pnData = 5;

	pnData = &nNewData;
	//nNewData = 5;
	*pnData = 5;

	//C++, use & and wont change
	int &rData = nNewData;
	rData = 5;

	*/

	int a = 1;
	// int *pnData = &a;
	// int * const pnData = &a
	int &pnData = a;
	int b = 2;
	int c = 3;

	pnData = 5;

	//r value reference
	int &&rNewData = 5;

	return 0;
}