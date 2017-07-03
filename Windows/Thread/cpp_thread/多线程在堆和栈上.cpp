#include <iostream>
#include <string>
#include <Windows.h>
#include <thread>
using namespace std;
int mainertwe()
{
	auto fun = [](const char* str){MessageBoxA(0, str, str, 0); };
	//thread t1(fun, "hello");//不常用的线程放在栈上
	//thread t11[2] = { thread(fun, "Hello"), thread(fun, "world") };//栈上的线程数组
	 
	
	//thread* t2 = new thread(fun, "Hello");//常用的，常驻的线程放在堆上
	
	//堆上的线程数组
// 	thread* p = new thread[2];
// 	p[0] = thread(fun, "Hello");
// 	p[1] = thread(fun, "World");
	
	//堆上的多线程没有自动初始化函数
	//thread* p2 = new thread{ thread(fun, "Hello"), thread(fun, "world") };
 

	system("pause");
	return 0;
}