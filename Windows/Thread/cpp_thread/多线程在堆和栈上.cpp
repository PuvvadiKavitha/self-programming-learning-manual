#include <iostream>
#include <string>
#include <Windows.h>
#include <thread>
using namespace std;
int mainertwe()
{
	auto fun = [](const char* str){MessageBoxA(0, str, str, 0); };
	//thread t1(fun, "hello");//�����õ��̷߳���ջ��
	//thread t11[2] = { thread(fun, "Hello"), thread(fun, "world") };//ջ�ϵ��߳�����
	 
	
	//thread* t2 = new thread(fun, "Hello");//���õģ���פ���̷߳��ڶ���
	
	//���ϵ��߳�����
// 	thread* p = new thread[2];
// 	p[0] = thread(fun, "Hello");
// 	p[1] = thread(fun, "World");
	
	//���ϵĶ��߳�û���Զ���ʼ������
	//thread* p2 = new thread{ thread(fun, "Hello"), thread(fun, "world") };
 

	system("pause");
	return 0;
}