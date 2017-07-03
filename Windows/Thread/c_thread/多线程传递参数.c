#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void run2(void* p)
{
	int* px = p;
	char str[10] = { 0 };
	sprintf(str, "%d号窗口", *px);
	MessageBoxA(0, str, str, 0);


}


int main2(void)
{
	int a[3] = { 1, 2, 3 };
	for (int i = 0; i < 3; i++)
	{
		//i不断变化，多个线程同时读取会出错 
		//_beginthread(run2, 0, &i);

		//必须传入固定的线程参数
		_beginthread(run2, 0, &a[i]);
	}


	system("pause");
	return 0;
}