#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
//字符串数组的二分查找法


//数组实现，速度没有指针快
char* binary_search_str_1(char* cmd[], int n, char* key_str)
{
	int low = 0;
	int high = n;
	int mid = 0;
	int res = 0;
	while (low < high)
	{
		//mid = low + (high - low) / 2;
        mid = (high + low) >> 1;//移位效率高
		res = strcmp(cmd[mid], key_str);//比较结果
		if (res < 0)
		{
			low = mid + 1;//不对称边界，低位加1
		}
		if (res > 0)
		{
			high = mid;//不对称边界，高位不加1
		}
		if (0 == res)
		{ 
			return cmd[mid];
		}
	}
	return NULL;
}

//指针实现，速度快
char* binary_search_str_2(char* cmd[], int n, char* key_str)
{ 

	char** low = cmd;
	char** high = cmd + n;
	char** mid = NULL; 
	int res = 0;

	while (low < high)
	{
		mid = low + ((high - low) >> 1);//指针没有加法
		res = strcmp(*mid, key_str);//比较结果
		if (res < 0)
		{
			low = mid + 1;
		}
		if (res > 0)
		{
			high = mid;
		}
		if (0 == res)
		{ 
			return *mid;
		}
	}
	return NULL;
}

 
//数组递归实现二分查找 
char* binary_search_str_3(char* cmd[], int n, char* key_str)
{
	static int low = 0;
	static int high = 10;//数组长度
	static int mid = 0;

	if (low >= high)//结束条件
	{
		return NULL;
	}
	else
	{
		mid = (high + low) >> 1;//移位效率高
		int res = strcmp(cmd[mid], key_str);//比较结果
		if (res < 0)
		{
			low = mid + 1;//不对称边界，低位加1
			return binary_search_str_3(cmd, n, key_str);
		}
		if (res > 0)
		{
			high = mid;//不对称边界，高位不加1
			return binary_search_str_3(cmd, n, key_str);
		}
		if (0 == res)//相等直接返回
		{
			return cmd[mid];
		}
	} 
}

 


int main1(void)
{
	char *cmd[10] = { "calc", "1234", "abcd", "ak47", "AMP", "M16", "notepad", "tasklist", "run", "mspaint" };
	sort_mao_pao(cmd, 10); 
	show_str(cmd);

	putchar('\n');
	puts(binary_search_str_1(cmd, 10, "tasklist"));

	putchar('\n');
	puts(binary_search_str_2(cmd, 10, "notepad"));	 

	putchar('\n');
	puts(binary_search_str_3(cmd, 10, "1234"));
	system("pause");
	return 0;
}