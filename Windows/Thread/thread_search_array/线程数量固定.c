#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#define FIND_NUM 565
#define THREAD_NUM 10
#define DATA_NUM 1000


int g_isFind = 0;//is find num?
int* g_findAddress = NULL;//find num`s address

struct ThreadInfo
{
	int* pstart;
	int length;
	int id;
	int find_num; 
};

void find(void* p)
{
	struct ThreadInfo* _info = (struct ThreadInfo*)p;
	printf("Thread %d start find\n", _info->id);
	for (int* px = _info->pstart; px < _info->pstart + _info->length; px++)
	{
		if (g_isFind)//Other thread is find?
		{
			printf("Thread %d stop find, other thread has find\n", _info->id);
			_endthread();
		}
		if (_info->find_num == (*px))//Find num
		{
			g_isFind = 1;
			g_findAddress = px;
			printf("Thread %d stop find, find %d, %p\n", _info->id, _info->find_num, g_findAddress);
			_endthread();
		}
	}
	printf("Thread %d stop find, no find\n", _info->id);
}



int main(void)
{
	int data[DATA_NUM] = { 0 };
	for (int i = 0; i < DATA_NUM; i++)
	{
		data[i] = i + 1;
	}
	//线程数量固定，开启10个线程
	struct ThreadInfo info[THREAD_NUM] = { 0 };
	for (int i = 0; i < THREAD_NUM; i++)
	{
		info[i].length = (DATA_NUM / THREAD_NUM);
		info[i].pstart = data + i * (info[i].length);
		info[i].id = i + 1;
		info[i].find_num = FIND_NUM;
		_beginthread(find, 0, &info[i]);//start thread find
	}



	getchar();
	return 0;
}