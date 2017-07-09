#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//需要用到一次砍一大半的插值查找，公式比较复杂


//数组实现，速度没有指针快
char* lglr_search_str_1(char* cmd[], int n, char* key_str)
{
	int low = 0;
	int high = n;
	int mid = 0;

	while (low < high)
	{
		//mid = low + (high - low) / 2;
		//mid = (high + low) >> 1;//移位效率高
		mid = low + (high - low) * (mid - low) / (high - low);
		if (strcmp(cmd[mid], key_str) < 0)
		{
			low = mid + 1;//不对称边界，低位加1
		}
		if (strcmp(cmd[mid], key_str) > 0)
		{
			high = mid;//不对称边界，高位不加1
		}
		if (0 == strcmp(cmd[mid], key_str))
		{
			return cmd[mid];
		}
	}
	return NULL;
}

//指针实现，速度快
char* lglr_search_str_2(char* cmd[], int n, char* key_str)
{

	char** low = cmd;
	char** high = cmd + n;
	char** mid = NULL;
	int i = 0;
	while (low < high)
	{
		//mid = low + ((high - low) >> 1);//指针没有加法
		//mid = low + (**high - **low) * (*key_str - **low) / (**high - **low);
		printf("%d次查找\n", ++i);
		if (strcmp(*mid, key_str) < 0)
		{
			low = mid + 1;
		}
		if (strcmp(*mid, key_str) > 0)
		{
			high = mid;
		}
		if (0 == strcmp(*mid, key_str))
		{
			printf("%d次找到%s\n", i, *mid);
			return *mid;
		}
	}
	return NULL;
}

int main3(void)
{
	char *cmd[10] = { "calc", "1234", "abcd", "ak47", "AMP", "M16", "notepad", "tasklist", "run", "mspaint" };
	sort_mao_pao(cmd, 10);
	show_str(cmd);

	putchar('\n');
	puts(lglr_search_str_2(cmd, 10, "ak47"));

	system("pause");
	return 0;
}