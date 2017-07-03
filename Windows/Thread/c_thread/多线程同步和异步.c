#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void run22(void* p)
{
	int* px = p;
	char str[10] = { 0 };
	sprintf(str, "%d号窗口", *px);
	MessageBoxA(0, str, str, 0);


}

int main234234(void)
{
	while (1)
	{
		//system("calc");同步，一个一个的，必须要等待上一个结束
		system("start calc");//异步，并行，不需要等待上一个结束
		Sleep(1000);
	}


	system("pause");
	return 0;
}

int main33(void)
{
	int a[3] = { 1, 2, 3 };
	for (int i = 0; i < 3; i++)
	{
		/*
		句柄（HANDLE），资源的标识。
		操作系统要管理和操作这些资源，都是通过句柄来找到对应的资源。
		按资源的类型，又可将句柄细分成
		图标句柄（HICON），
		光标句柄（HCURSOR），
		窗口句柄（HWND），
		应用程序实例句柄（HINSTANCE）等等各种类型的句柄。
		操作系统给每一个窗口指定的一个唯一的标识号即窗口句柄
		*/
		HANDLE handle = _beginthread(run22, 0, &a[i]);
		//通过窗口的句柄，设置为同步执行
		WaitForSingleObject(handle, INFINITE);//infinite
	}


	system("pause");
	return 0;
}