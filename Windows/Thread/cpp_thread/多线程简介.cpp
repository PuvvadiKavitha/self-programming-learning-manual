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
	//���߳�ͬ��ִ��
	run();
	run();
	run();

	system("pause");
	return 0;
}

int main1()
{
	//���߳��첽ִ��
	thread t1(run);//C++�Ķ��߳���
	thread t2(run);
	thread t3(run);

	system("pause");
	return 0;
}