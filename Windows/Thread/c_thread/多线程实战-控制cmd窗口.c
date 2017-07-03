#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <process.h>
 
int i = 0;

void setTime(void* p)
{
	while (1)
	{
		char str[20] = { 0 };
		sprintf(str, "title current time %d s", i);
		i++;
		system(str);
		Sleep(1000);
	}
}

void run33(void* p)
{

	while (1)
	{
		if (3 == i)
		{
			system("start calc");
		}
		else if (10 == i)
		{
			system("start notepad");
			//_endthread();//结束当前线程
		}
		else if (15 == i)
		{
			system("start tasklist & pause");
		}
		Sleep(1000);
	}


}



int main234(void)
{
	_beginthread(setTime, 0, NULL);
	_beginthread(run33, 0, NULL);
	system("pause");
	return 0;
}