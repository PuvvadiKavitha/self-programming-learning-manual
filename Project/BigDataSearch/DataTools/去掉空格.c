#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//是空格, 指针就不同步
//不是空格, 指针就同步
void eatSpaces(char* str)
{
	int i = 0;
	int j = 0;
	while ((str[i] = str[j++]) != '\0')
	{
		if (str[i] != ' ')//不是空格，同步
		{
			i++;
		}
	}
}

void eatSpaces_1(char* str)
{ 
	char* p1 = str;
	char* p2 = str;
	//一行代码搞定，必须记住
	//while ((*p1 = *(p2++)) != '\0' ? (*p1 != ' ' ? p1++ : 1) : 0); 

	//(*p1 != ' ')加上括号，好习惯
	while ((*p1 = (*p2++)) != '\0' ? ((*p1 != ' ') ? p1++ : 1) : 0);
	 
}


int main45(void)
{
	char str[100] = "love    cheng   zhi  ";
	//eatSpaces(str);
	eatSpaces_1(str);
	puts(str);
	system("pause");
	return 0;
}
