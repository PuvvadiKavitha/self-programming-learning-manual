#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20000000

char path[256] = "E:\\数据资料\\大数据\\qq.txt";
char bin_path[256] = "E:\\数据资料\\大数据\\qq.bin";
struct QQ* g_p = NULL;

struct QQ
{
	int num;
	char str[50];
};


void readDiskFileToMemory(char* file_path)
{
	FILE* f = fopen(file_path, "r");
	if (NULL == f)
	{
		printf("QQ file open fail!\n");
		system("pause");
		return -1;
	}
	printf("QQ file open success!\n");

	g_p = (struct QQ*)malloc(sizeof(struct QQ) * N);
	if (NULL == g_p)
	{
		printf("Memory malloc fail!\n");
		system("pause");
		return -2;
	}

	//char str1[50] = { 0 };
	//char str2[50] = { 0 };
	char temp_str[256] = { 0 };
	for (int i = 0; i < N; i++)
	{
		//获取一行文本
		fgets(temp_str, 256, f);

		eatSpaces(temp_str);//去掉空格
		eatEnter(temp_str);//去掉换行

		char* pstr = strstr(temp_str, "-");
		if (NULL == pstr)
		{
			printf("该行不符合条件\n");
			system("pause");
			return -1;
		}
		*pstr = '\0';
		//strcpy(str1, temp_str);
		//strcpy(str2, pstr + 4);
		 
		//拷贝到内存结构体
		g_p[i].num = atoi(temp_str);
		strcpy(g_p[i].str, pstr + 4);
	}
	fclose(f);
	printf("QQ file close success!\n");
}


void writeBinaryFileToDisk(char* file_path)
{
	FILE* f = fopen(file_path, "wb");
	if (NULL == f)
	{
		printf("QQ.bin file open fail!\n");
		system("pause");
		return -1;
	}
	printf("QQ.bin file open success!\n");

	int ret = fwrite(g_p, sizeof(struct QQ), N, f);
	if (ret != 0)
	{
		printf("二进制文件写入磁盘成功\n");
	}
	fclose(f); 
	printf("QQ.bin file close success!\n");
}


void searchDiskFile(char* file_path, int i)
{
	FILE* f = fopen(file_path, "r");
	if (NULL == f)
	{
		printf("QQ.bin file open fail!\n");
		system("pause");
		return -1;
	}
	printf("QQ.bin file open success!\n");
	struct QQ temp;

	int ret_seek = fseek(f, i * sizeof(struct QQ), SEEK_SET);
	printf("ret_seek = %d\n", ret_seek);
	if (ret_seek != 0)
	{
		printf("要查找的数据不在QQ.bin文件中\n");
		system("pause");
		return -1;
	} 

	int read_num = fread(&temp, sizeof(struct QQ), 1, f);
	if (0 == read_num)
	{
		printf("QQ.bin file write to memory fail!\n");
		system("pause");
		return -1;
	}
	printf("find:\t%d\t%d\n", temp.num, temp.str);
	fclose(f);
	printf("QQ.bin file close success!\n");
}

void init()
{
	readDiskFileToMemory(path);
	writeBinaryFileToDisk(bin_path);
}


int maingdssd(void)
{
	time_t start;
	time_t end;

	time(&start);
	
	
	//init();
	searchDiskFile(bin_path, 18999999);
	
	 
	
	time(&end);
	printf("time = %.1f s\n", (float)(end - start));

	system("pause");
	return 0;
}