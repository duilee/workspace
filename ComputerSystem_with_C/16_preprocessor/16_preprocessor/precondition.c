#include <stdio.h>
#define MYUNICODE

#ifdef MYUNICODE
typedef wchar_t TCHAR;
#define _T(string)	L##string
#define PRINT	wprintf
#else
typedef char TCHAR;
#define _T(string)	string
#define PRINT	printf
#endif

void precondition(void)
{
	TCHAR szData[16] = _T("Test string");
	PRINT(_T("%s\n"), szData);
	PRINT(_T("%d, %d\n"), sizeof(TCHAR), sizeof(szData));
}