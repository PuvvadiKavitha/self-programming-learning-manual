#include <iostream>
#include <thread>
#include <Windows.h>
//1.R表达式实现多线程
//2.join  detach,主线程与子线程设置
//3.auto n = thread::hardware_concurrency();//4核心8线程显示4
//4.线程传递参数

//以后的多线程函数都使用Lambda表达式

using namespace std;
using namespace std::this_thread;

int main435345()
{
	auto fun = [](){cout << get_id() << endl; };
	//fun();
	
	
	thread t[3]{thread(fun), thread(fun), thread(fun)};
	for (int i = 0; i < 3; i++)
	{
		t[i].detach();
	}
	system("pause");
	return 0;
}

int main789689()
{
	cout << thread::hardware_concurrency() << "核心"  << endl;
	system("pause");
	return 0;
}

int main6786()
{
	//必须是const char* str
	auto fun = [](const char* str){MessageBoxA(0, str, str, 0); };
	thread t1(fun, "Hello");
	thread t2(fun, "World");

	system("pause");
	return 0;
}

int main3453()
{
	auto fun = [](){MessageBoxA(0, "Hello", "World", 0); };
	thread t1(fun);
	thread t2(fun);

	system("pause");
	return 0;
}

