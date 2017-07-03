#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//È¥µô»»ÐÐ
void eatEnter(char* str)
{ 
	while (*str != '\0')
	{
		if ('\n' == *str)
		{
			*str = '\0';
		}
		str++;
	}
}


int main4(void)
{
	char str[] = { 'H', 'e', 'l', 'l', 'o', '\n', '\0' };
	printf(str);

	eatEnter(str);
	printf(str);

	system("pause");
	return 0;
}
