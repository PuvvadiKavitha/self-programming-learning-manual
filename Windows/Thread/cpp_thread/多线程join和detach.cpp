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
	//���߳��첽ִ��
	thread t1(run2);//C++�Ķ��߳���
	thread t2(run2);
	thread t3(run2);

	//t1.join();
	//t2.join();
	//t3.join();//���̱߳���ȴ����˳������˳�

	t1.detach();
	t2.detach();
	t3.detach();//���߳��˳������߳�Ҳ�˳�

	system("pause");
	return 0;
}