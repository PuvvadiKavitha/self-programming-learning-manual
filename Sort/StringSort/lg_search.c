#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��Ҫ�õ�һ�ο�һ���Ĳ�ֵ���ң���ʽ�Ƚϸ���


//����ʵ�֣��ٶ�û��ָ���
char* lglr_search_str_1(char* cmd[], int n, char* key_str)
{
	int low = 0;
	int high = n;
	int mid = 0;

	while (low < high)
	{
		//mid = low + (high - low) / 2;
		//mid = (high + low) >> 1;//��λЧ�ʸ�
		mid = low + (high - low) * (mid - low) / (high - low);
		if (strcmp(cmd[mid], key_str) < 0)
		{
			low = mid + 1;//���ԳƱ߽磬��λ��1
		}
		if (strcmp(cmd[mid], key_str) > 0)
		{
			high = mid;//���ԳƱ߽磬��λ����1
		}
		if (0 == strcmp(cmd[mid], key_str))
		{
			return cmd[mid];
		}
	}
	return NULL;
}

//ָ��ʵ�֣��ٶȿ�
char* lglr_search_str_2(char* cmd[], int n, char* key_str)
{

	char** low = cmd;
	char** high = cmd + n;
	char** mid = NULL;
	int i = 0;
	while (low < high)
	{
		//mid = low + ((high - low) >> 1);//ָ��û�мӷ�
		//mid = low + (**high - **low) * (*key_str - **low) / (**high - **low);
		printf("%d�β���\n", ++i);
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
			printf("%d���ҵ�%s\n", i, *mid);
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