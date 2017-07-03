#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int getLines_2(char* file_path)
{
	FILE* f = fopen(file_path, "r");
	if (NULL == f)
	{
		printf("�ļ���ʧ��\n");
		return -1;
	}
	else
	{
		int lines = 0;
		int min_width = 2048;
		int max_width = -1;
		int line_length = 0;
		while (!feof(f))//feof�����ļ�ĩβ����1
		{
			char str[1024] = { 0 };
			fgets(str, 1024, f);//��ȡһ��
			eatSpaces(str);
			eatEnter(str);
			line_length = strlen(str);
			//��ȡ�еĳ��Ȳ�̫׼ȷ
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
		printf("����� = %d, ��̵��� = %d\n", max_width, min_width);
		return lines;
	}
}
//qq���ݻ�ȡ�����������
int  getmaxW(char* file_path)
{

	FILE *pf = fopen(file_path, "r");//��ȡ
	if (pf == NULL)
	{

		return -1;
	}
	else
	{
		int width = -1;
		while (!feof(pf))//û�е��ļ�ĩβ�ͼ���
		{
			char str[1024] = { 0 };
			fgets(str, 1024, pf);//��һ��
			int nowwidth = strlen(str);//��ȡ����
			if (nowwidth > width)//�����ֵ����width
			{
				width = nowwidth;
			} 
		} 
		fclose(pf);//�ر�

		return width; 

	} 

}
int main(void)
{
	time_t start;
	time_t end;
	time(&start);

	char path[256] = "E:\\��������\\������\\qq.txt";
	printf("getmaxW = %d\n", getmaxW(path));

	time(&end);
	printf("time = %.1f s\n", (float)(end - start));

	system("pause");
	return 0;
}
