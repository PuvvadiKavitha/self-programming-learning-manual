#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int getLines(char* file_path)
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
		
		while (!feof(f))//feof�����ļ�ĩβ����1
		{ 
			char str[256] = { 0 };
			fgets(str, 256, f);//��ȡһ��
			lines++;
		}
		fclose(f);
		return lines;
	} 
}


int main34534(void)
{
	time_t start;
	time_t end; 
	time(&start);

	char path[256] = "E:\\��������\\������\\qq.txt";
	printf("lines = %d\n", getLines(path));
	
	time(&end);
	printf("time = %.1f s\n", (float)(end - start));

	system("pause");
	return 0;
}
