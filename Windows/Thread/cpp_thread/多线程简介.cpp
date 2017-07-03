#include <iostream> 
#include <Windows.h>
#include <thread>
using namespace std;

void run()
{
	MessageBoxA(0, "AAAA", "BBBB", 0);
}
int main2()
{
	//单线程同步执行
	run();
	run();
	run();

	system("pause");
	return 0;
}

int main1()
{
	//多线程异步执行
	thread t1(run);//C++的多线程类
	thread t2(run);
	thread t3(run);

	system("pause");
	return 0;
}