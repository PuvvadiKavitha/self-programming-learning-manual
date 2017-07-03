#include <iostream>
#include <list>
#include <deque>
using namespace std;
int mainasdqweqw()
{
	int ival;
	list<int> ilist;
	deque<int> evenDeque, oddDeque;
	while (cin >> ival)
	{
		ilist.push_back(ival);
	}
	for (list<int>::iterator iter_begin = ilist.begin(); iter_begin != ilist.end(); iter_begin++)
	{
		if (*iter_begin % 2 == 0)
		{
			evenDeque.push_back(*iter_begin);
		}
		else
		{
			oddDeque.push_back(*iter_begin);
		}
	}

	deque<int>::iterator deque_begin = evenDeque.begin();
	cout << "偶数的deque" << endl;
	while (deque_begin != evenDeque.end())
	{
		cout << *deque_begin << " ";
		deque_begin++;
	}
	cout << endl;
	cout << "奇数的deque" << endl;
	deque_begin = oddDeque.begin();
	while (deque_begin != oddDeque.end())
	{
		cout << *deque_begin << " ";
		deque_begin++;
	}

	system("pause");
	return 0;
}
