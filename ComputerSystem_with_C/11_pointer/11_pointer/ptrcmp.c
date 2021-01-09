#include <stdio.h>
#include <string.h>

int ptrmemcmp(void)
{
	char szBuffer[12] = { "TestString" };
	char *pszData = "TestString";
	
	// when values in two memories are the same
	printf("%d\n", memcmp(szBuffer, pszData, 10));
	
	// when value in left memory is bigger
	printf("%d\n", memcmp("teststring", pszData, 10));

	// when value in right memory is bigger
	printf("%d\n", memcmp("DataString", pszData, 10));

	//following compares address of the memory, not the values
	printf("%d\n", szBuffer == pszData);
	printf("%d\n", "TestString" == pszData);
	printf("%d\n", "DataString" == pszData);

	//following uses strcmp with no specific length value given
	printf("%d\n", strcmp(szBuffer, pszData));
	printf("%d\n", strcmp("TestString", pszData));
	printf("%d\n", strcmp("Test", "TestString"));
	return 0;

}

int ptrsearch(void)
{
	char szBuffer[32] = { "I am a boy." };

	// print address of the array
	printf("%p\n", szBuffer);

	// search within given text, return the address
	printf("%p\n", strstr(szBuffer, "am"));
	printf("%p\n", strstr(szBuffer, "boy"));

	// get index 
	printf("Index: %d\n", strstr(szBuffer, "am") - szBuffer);
	printf("Index: %d\n", strstr(szBuffer, "boy") - szBuffer);

	return 0;
}