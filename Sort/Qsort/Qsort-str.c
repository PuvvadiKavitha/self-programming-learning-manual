#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(void* p1, void* p2)
{
	int* px1 = p1;
	int* px2 = p2;
	return strcmp(px1, px2);
}


int main2121()
{
	char * str[10] = { "abc", "abd", "bcf", "123", "456", "qwe", "ABC", "ABF", "xyz", "X" };//Ö¸ÕëÊý×é
	qsort(str, sizeof(str) / sizeof(str[0]), sizeof(str[0]), compare);
	
	for (int i = 0; i < 10; i++)
	{
		printf("%s\n", str[i]);
	}
	
	system("pause");
	return 0;
}