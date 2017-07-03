#include <iostream> 
#include <Windows.h>
#include <thread>
using namespace std;

void run2()
{
	MessageBoxA(0, "AAAA", "BBBB", 0);
}
 

int main21221()
{
	//多线程异步执行
	thread t1(run2);//C++的多线程类
	thread t2(run2);
	thread t3(run2);

	//t1.join();
	//t2.join();
	//t3.join();//主线程必须等待我退出才能退出

	t1.detach();
	t2.detach();
	t3.detach();//主线程退出，子线程也退出

	system("pause");
	return 0;
}