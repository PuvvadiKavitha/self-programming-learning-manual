#include <iostream>
#include <list>
using namespace std;
int main3131()
{
	//ʹ��list�ĵ�����
	list<int> ilist;
	list<int>::iterator itet_begin = ilist.begin();
	list<int>::iterator iter_end = ilist.end();
	//�������ʹ��end������
	while (iter_end != itet_begin)
	{
		cout << *(--iter_end);
	}

	system("pause");
	return 0;
}