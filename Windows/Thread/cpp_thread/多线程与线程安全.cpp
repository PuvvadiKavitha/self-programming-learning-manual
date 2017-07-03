#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <atomic>
using namespace std;
int num = 0;//多线程使用全局变量，线程数量较多的时候会出现访问冲突
mutex mlock;//全局变量的锁，实现锁定 但是会增加内存的访问时间 开锁解锁浪费时间 
atomic_int ato_num;//原子变量，一定可以保证线程安全
int main5645()
{
	auto fun = []()
	{
		for (int i = 0; i < 10000; i++)
		{
			mlock.lock();
			ato_num += 1;
			mlock.unlock();
		}
	};

	time_t start;
	time_t end;
	time(&start);

	for (int i = 0; i < 1000; i++)
	{
		thread* p = new thread(fun);
		//p->join();
	}
	time(&end);
	cout << ato_num << endl;
	cout << (float)(end - start) << endl;
	system("pause");
	return 0;
}