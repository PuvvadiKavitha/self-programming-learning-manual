#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void show_str(char* cmd[10])
{
	for (int i = 0; i < 10; i++)
	 {
		puts(cmd[i]);//自动换行 
	 }
}

//冒泡排序
void sort_mao_pao(char* cmd[], int n)
{
	for (int i = 0; i < n - 1; i++)//n - 1
	{
		for (int j = 0; j < n - 1 - i; j++)//n - 1 - i
		{
			if (strcmp(cmd[j], cmd[j + 1]) > 0)//字符串函数比大小  从小到大
			{
				char* temp = cmd[j];
				cmd[j] = cmd[j + 1];
				cmd[j + 1] = temp;
			}
		}
	} 
}


int main1(void)
{
	char *cmd[10] = { "calc", "1234", "abcd", "ak47", "AMP", "M16", "notepad", "tasklist", "run", "mspaint" };
	show_str(cmd);
	sort_mao_pao(cmd, 10);
	putchar('\n');
	show_str(cmd);
	system("pause");
	return 0;
}