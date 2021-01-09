#pragma once

class CMyNode
{
	friend class CMyList;
public:
	CMyNode(void);
	virtual ~CMyNode(void);

	CMyNode* GetNext(void) const { return pNext;  }

	//make virtual functions for future management
	virtual const char* GeyKey(void) = 0;
	virtual void PrintNode(void) = 0;

private:
	// member for linked list
	CMyNode *pNext;
};

