#include "stdafx.h"

class CMyUSB
{
public:
	virtual int GetUsbVersion() = 0;
	virtual int GetTransferRate() = 0;
};

class CMySerial
{
public:
	virtual int GetSignal() = 0;
	virtual int GetRate() = 0;
};

class CMyDevice : public CMyUSB, public CMySerial
{
public:
	// USB interface 
	virtual int GetUsbVersion() { return 0; }
	virtual int GetTransferRate() { return 0; }

	//serial interface
	virtual int GetSignal() { return 0; }
	virtual int GetRate() { return 0; }
};

int muti_interface(void)
{
	CMyDevice dev;

	return 0;
}