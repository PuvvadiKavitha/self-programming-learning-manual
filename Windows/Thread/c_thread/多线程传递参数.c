#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void run2(void* p)
{
	int* px = p;
	char str[10] = { 0 };
	sprintf(str, "%d�Ŵ���", *px);
	MessageBoxA(0, str, str, 0);


}


int main2(void)
{
	int a[3] = { 1, 2, 3 };
	for (int i = 0; i < 3; i++)
	{
		//i���ϱ仯������߳�ͬʱ��ȡ����� 
		//_beginthread(run2, 0, &i);

		//���봫��̶����̲߳���
		_beginthread(run2, 0, &a[i]);
	}


	system("pause");
	return 0;
}