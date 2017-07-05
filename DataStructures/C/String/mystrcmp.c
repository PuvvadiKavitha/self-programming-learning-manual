#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int mystrcmp(const char* str1, const char* str2)
{
	int i = 0;
	int res = 0;

	/* Jump all euqal char. */
	while ((str1[i] == str2[i]) != '\0')
		i++;

	/* If all char is equal, then str1 == str2 */
	if (('\0' == str1[i]) && ('\0'== str2[i]))
		return 0;
	else
		res = str1[i] - str2[i];

	if (res > 0)
		return 1;

	if (res < 0)
		return -1;

}

/* Recursive */
int mystrcmp_r(const char* str1, const char* str2)
{
	/* *str1 == '\0' */
	if ('\0' == (*str1 && *str2))
		return -1;

	/* *str2 == '\0' */
	if ('\0' == (*str2 && *str1))
		return 1;

	if (('\0' == *str1) && ('\0' == *str2))
		return 0;

	if (*str1 < *str2)
		return -1;

	if (*str1 > *str2)
		return 1;

	if (*str1 == *str2)
		return mystrcmp_r(str1 + 1, str2 + 1);
}



int main(void)
{
	// -1
	printf("%d\n", strcmp("AAABCD", "AAABCG"));
	// -1
	printf("%d\n", mystrcmp("AAABCD", "AAABCG"));
	// -1
	printf("%d\n", mystrcmp_r("AAABCD", "AAABCG"));
	return 0;
}



