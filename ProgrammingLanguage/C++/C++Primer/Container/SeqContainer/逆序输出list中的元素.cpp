#include <iostream>
#include <list>
using namespace std;
int main3131()
{
	//使用list的迭代器
	list<int> ilist;
	list<int>::iterator itet_begin = ilist.begin();
	list<int>::iterator iter_end = ilist.end();
	//逆序输出使用end迭代器
	while (iter_end != itet_begin)
	{
		cout << *(--iter_end);
	}

	system("pause");
	return 0;
}