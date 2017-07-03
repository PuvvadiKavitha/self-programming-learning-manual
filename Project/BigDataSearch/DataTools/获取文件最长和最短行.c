#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int getLines_2(char* file_path)
{
	FILE* f = fopen(file_path, "r");
	if (NULL == f)
	{
		printf("文件打开失败\n");
		return -1;
	}
	else
	{
		int lines = 0;
		int min_width = 2048;
		int max_width = -1;
		int line_length = 0;
		while (!feof(f))//feof到达文件末尾返回1
		{
			char str[1024] = { 0 };
			fgets(str, 1024, f);//获取一行
			eatSpaces(str);
			eatEnter(str);
			line_length = strlen(str);
			//获取行的长度不太准确
			if (line_length != 0)
			{
				if (line_length > max_width)
				{
					max_width = line_length;
				}
				if (line_length < min_width)
				{
					min_width = line_length;
				}
			} 
			lines++;
		}
		fclose(f);
		printf("最长的行 = %d, 最短的行 = %d\n", max_width, min_width);
		return lines;
	}
}
//qq数据获取行最大有问题
int  getmaxW(char* file_path)
{

	FILE *pf = fopen(file_path, "r");//读取
	if (pf == NULL)
	{

		return -1;
	}
	else
	{
		int width = -1;
		while (!feof(pf))//没有到文件末尾就继续
		{
			char str[1024] = { 0 };
			fgets(str, 1024, pf);//读一行
			int nowwidth = strlen(str);//获取长度
			if (nowwidth > width)//把最大值存入width
			{
				width = nowwidth;
			} 
		} 
		fclose(pf);//关闭

		return width; 

	} 

}
int main(void)
{
	time_t start;
	time_t end;
	time(&start);

	char path[256] = "E:\\数据资料\\大数据\\qq.txt";
	printf("getmaxW = %d\n", getmaxW(path));

	time(&end);
	printf("time = %.1f s\n", (float)(end - start));

	system("pause");
	return 0;
}
