#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//�ǿո�, ָ��Ͳ�ͬ��
//���ǿո�, ָ���ͬ��
void eatSpaces(char* str)
{
	int i = 0;
	int j = 0;
	while ((str[i] = str[j++]) != '\0')
	{
		if (str[i] != ' ')//���ǿո�ͬ��
		{
			i++;
		}
	}
}

void eatSpaces_1(char* str)
{ 
	char* p1 = str;
	char* p2 = str;
	//һ�д���㶨�������ס
	//while ((*p1 = *(p2++)) != '\0' ? (*p1 != ' ' ? p1++ : 1) : 0); 

	//(*p1 != ' ')�������ţ���ϰ��
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
