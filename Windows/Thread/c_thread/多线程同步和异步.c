#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void run22(void* p)
{
	int* px = p;
	char str[10] = { 0 };
	sprintf(str, "%d�Ŵ���", *px);
	MessageBoxA(0, str, str, 0);


}

int main234234(void)
{
	while (1)
	{
		//system("calc");ͬ����һ��һ���ģ�����Ҫ�ȴ���һ������
		system("start calc");//�첽�����У�����Ҫ�ȴ���һ������
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
		�����HANDLE������Դ�ı�ʶ��
		����ϵͳҪ����Ͳ�����Щ��Դ������ͨ��������ҵ���Ӧ����Դ��
		����Դ�����ͣ��ֿɽ����ϸ�ֳ�
		ͼ������HICON����
		�������HCURSOR����
		���ھ����HWND����
		Ӧ�ó���ʵ�������HINSTANCE���ȵȸ������͵ľ����
		����ϵͳ��ÿһ������ָ����һ��Ψһ�ı�ʶ�ż����ھ��
		*/
		HANDLE handle = _beginthread(run22, 0, &a[i]);
		//ͨ�����ڵľ��������Ϊͬ��ִ��
		WaitForSingleObject(handle, INFINITE);//infinite
	}


	system("pause");
	return 0;
}