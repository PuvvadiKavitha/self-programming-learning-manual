#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void run(void* p)
{
	MessageBoxA(0, "hello", "chengzhi", 0);
}


int main1(void)
{
	for (int i = 0; i < 3; i++)
	{
		_beginthread(run, 0, NULL);//多线程异步执行
	}
	system("pause");
	return 0;
}