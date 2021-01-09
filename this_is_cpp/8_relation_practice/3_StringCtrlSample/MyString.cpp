#include "stdafx.h"
#include "MyString.h"


CMyString::CMyString()
	: m_pszData(NULL)
	, m_nLength(0)
{
}


CMyString::~CMyString()
{
}


int CMyString::SetString(const char* pszParam)
{
	// reset to initialization
	Release();

	//if NULL in put return 0
	if (pszParam == NULL)
		return 0;

	//if length == 0, then return 0
	int nLength = strlen(pszParam);

	if (nLength == 0)
		return 0;

	// add 1 to the length to count for NULL at the eos
	m_pszData = new char[nLength + 1];

	//save string array to new memory
	strcpy_s(m_pszData, sizeof(char)*(nLength + 1), pszParam);
	m_nLength = nLength;

	//call future
	OnSetString(m_pszData, m_nLength);

	return m_nLength;
}

const char* CMyString::GetString() const
{
	return m_pszData;
}

void CMyString::Release()
{
	// reset the members as function can get called multiple times
	if (m_pszData != NULL)
		delete[] m_pszData;

	m_pszData = NULL;
	m_nLength = 0;
}

CMyString::CMyString(const CMyString &rhs)
	: m_nLength(0), m_pszData(NULL)
{
	this->SetString(rhs.GetString());
}

CMyString& CMyString::operator=(const CMyString &rhs)
{
	if (this != &rhs)
		this->SetString(rhs.GetString());
	return *this;
}

CMyString::CMyString(const char *pszParam)
	: m_pszData(NULL), m_nLength(0)
{
	SetString(pszParam);
}

CMyString::CMyString(CMyString &&rhs)
	: m_pszData(NULL), m_nLength(0)
{
	cout << "CMyString move constructor call" << endl;

	//shalow copy is fine. rhs will be deleted since its temporary
	m_pszData = rhs.m_pszData;
	m_nLength = rhs.m_nLength;

	//reset temporary variables
	rhs.m_pszData = NULL;
	rhs.m_nLength = 0;
}

int CMyString::GetLength() const
{
	return m_nLength;
}

int CMyString::Append(const char* pszParam)
{
	// check the parameter
	if (pszParam == NULL)
		return 0;

	int nLenParam = strlen(pszParam);

	if (nLenParam == 0)
		return 0;

	//if no previously set string, set it to current parameter
	if (m_pszData == NULL)
	{
		SetString(pszParam);

		return m_nLength;
	}

	// back up current string length
	int nLenCur = m_nLength;

	// new memory allocation 
	char *pszResult = new char[nLenCur + nLenParam + 1];

	//combine string
	strcpy_s(pszResult, sizeof(char)*(nLenCur + 1), m_pszData);
	strcpy_s(pszResult + (sizeof(char) * nLenCur), sizeof(char)*(nLenParam + 1), pszParam);

	// delete previous string
	Release();
	m_pszData = pszResult;
	m_nLength = nLenCur + nLenParam;

	return m_nLength;
}

CMyString CMyString::operator+(const CMyString &rhs)
{
	CMyString strResult(m_pszData);
	strResult.Append(rhs.GetString());

	return strResult;
}

CMyString& CMyString::operator+=(const CMyString &rhs)
{
	Append(rhs.GetString());

	return *this;
}
char& CMyString:: operator[](int nIndex)
{
	cout << "operator[]" << endl;
	return m_pszData[nIndex];
}

int CMyString::operator==(const CMyString &rhs)
{
	if (m_pszData != NULL && rhs.m_pszData != NULL)
		if (strcmp(m_pszData, rhs.m_pszData) == 0)
			return 1;

	return 0;
}

int CMyString::operator!=(const CMyString &rhs)
{
	if (m_pszData != NULL && rhs.m_pszData != NULL)
		if (strcmp(m_pszData, rhs.m_pszData) == 0)
			return 0;

	return 1;
}


void CMyString::OnSetString(char * pszData, int nLength)
{
}


CMyString operator+(const char *pszParam, const CMyString &strParam)
{
	CMyString strResult(pszParam);
	strResult.Append(strParam.m_pszData);

	return strResult;
}