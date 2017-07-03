#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <process.h> 
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
/*
多线程切割检索
1000个数据   
开启能整除线程5：则每个线程处理200个数据
开启不能整除线程7：
1.先求余数：1000 - (1000 / 6) * 6 = 4,意味着最后一个线程只需要处理4个数据
2.求前面的相等长度的线程的处理数据长度：1000 / (7 - 1) = 166
3.余数公式：6 * 166 + 4 = 1000
*/

int main(void)
{
	int data[DATA_NUM] = { 0 };
	for (int i = 0; i < DATA_NUM; i++)
	{
		data[i] = i + 1;
	}
	int _thread_num = 0;
	printf("输入要开启的线程的数量:");
	scanf("%d", &_thread_num);
	int _find_num = 0;
	printf("\n输入要查找的数据[0-1000]:");
	scanf("%d", &_find_num);

	if (0 == DATA_NUM % _thread_num)//能整除
	{
		struct ThreadInfo* _info = malloc(sizeof(struct ThreadInfo) * _thread_num);
		for (int i = 0; i < _thread_num; i++)
		{
			_info[i].length = DATA_NUM / _thread_num;
			_info[i].pstart = data + i * (_info[i].length);
			_info[i].id = i + 1;
			_info[i].find_num = _find_num;
			_beginthread(find, 0, &_info[i]);
		}
	}
	else//不能整除
	{
		struct ThreadInfo* _info = malloc(sizeof(struct ThreadInfo) * _thread_num);
		//先处理前面长度相等的线程
		for (int i = 0; i < _thread_num - 1; i++)
		{
			_info[i].length = DATA_NUM / (_thread_num - 1);
			_info[i].pstart = data + i * (_info[i].length);
			_info[i].id = i + 1;
			_info[i].find_num = _find_num;
			_beginthread(find, 0, &_info[i]);
		}
		{
			//处理最后一段剩余的数据段的线程
			int i = _thread_num - 1;
			//10 - (10 / 3) * 3 = 1 = 余数
			_info[i].length = DATA_NUM - (DATA_NUM / (_thread_num - 1)) * (_thread_num - 1);//求余数的公式
			_info[i].pstart = data + (DATA_NUM / (_thread_num - 1)) * (_thread_num - 1);
			_info[i].id = i + 1;
			_info[i].find_num = _find_num;
			_beginthread(find, 0, &_info[i]);
		}
	}



	system("pause");
	return 0;
}