#pragma once
class CMyString
{
public:
	// generator
	CMyString();
	//delete
	~CMyString();

	// copy constructor
	CMyString(const CMyString &rhs);
	// converting constructor
	explicit CMyString(const char *pszParam);
	//move constructor
	CMyString(CMyString &&rhs);

private:
	// pointer for string arrry dynamic allocation
	char* m_pszData;
	// length of the string array
	int m_nLength;

public:
	int SetString(const char* pszParam);
	const char* GetString() const;
	void Release();
	// operator constructor for =
	CMyString& operator=(const CMyString &rhs);
	// operator constructor for char*
	operator char*() const
	{
		return m_pszData;
	};

	int GetLength() const;
	int Append(const char* pszParam);
	CMyString operator+(const CMyString &rhs);
	CMyString& operator+=(const CMyString &rhs);

	char& operator[](int nIndex);
	int operator==(const CMyString &rhs);
	int operator!=(const CMyString &rhs);
	virtual void OnSetString(char * pszData, int nLength);

	friend CMyString operator+(const char *pszParam, const CMyString &strParam);
};