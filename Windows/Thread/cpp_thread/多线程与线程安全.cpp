#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <atomic>
using namespace std;
int num = 0;//���߳�ʹ��ȫ�ֱ������߳������϶��ʱ�����ַ��ʳ�ͻ
mutex mlock;//ȫ�ֱ���������ʵ������ ���ǻ������ڴ�ķ���ʱ�� ���������˷�ʱ�� 
atomic_int ato_num;//ԭ�ӱ�����һ�����Ա�֤�̰߳�ȫ
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