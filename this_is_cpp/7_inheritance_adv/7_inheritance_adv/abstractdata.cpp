#include "stdafx.h"
#include <iostream>
using namespace std;

#define DEFAULT_FARE 1000

/////////first developer
class CPerson
{
public:
	CPerson(){ }
	virtual ~CPerson() {
		cout << "virtual ~CPerson()" << endl;
	}

	// interface for calculating fare
	virtual void CalcFare() = 0;
	
	virtual unsigned int GetFare(){ return m_nFare; }

protected:
	unsigned int m_nFare = 0;
};

//////first or second developer
class CBaby : public CPerson
{
public:
	//fare for age 0~7
	virtual void CalcFare() {
		m_nFare = 0; //0%
	}
};

class CChild : public CPerson
{
public:
	//fare for age 8~13
	virtual void CalcFare() {
		m_nFare = DEFAULT_FARE * 50 / 100; //50%
	}
};

class CTeen : public CPerson
{
public:
	//fare for age 14~19
	virtual void CalcFare() {
		m_nFare = DEFAULT_FARE * 75 / 100; //75%
	}
};

class CAdult : public CPerson
{
public:
	//fare for age 20+
	virtual void CalcFare() {
		m_nFare = DEFAULT_FARE; //100%
	}
};

//user code
int getfareprice(void)
{
	CPerson* arList[3] = { 0 };
	int nAge = 0;

	//inser data
	for (auto &person : arList)
	{
		cout << "Enter Age:";
		cin >> nAge;
		if (nAge < 8)
			person = new CBaby;

		else if (nAge < 14)
			person = new CChild;

		else if (nAge < 20)
			person = new CTeen;

		else
			person = new CAdult;

		// calculate fare according to the class
		person->CalcFare();
	}

	// 2. output data
	for (auto person : arList)
		cout << person->GetFare() << endl;

	//3. delete data
	for (auto person : arList)
		delete person;

	return 0;
}