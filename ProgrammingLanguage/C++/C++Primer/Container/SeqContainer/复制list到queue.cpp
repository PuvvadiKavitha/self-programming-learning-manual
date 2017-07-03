#include <iostream>
#include <list>
#include <deque>
using namespace std;
int main123sdfsdf()
{
	list<int> ilist;
	deque<int> evenDq, oddDq;
	int ival;
	while (cin >> ival)
	{
		ilist.push_back(ival);
	}
	for (list<int>::iterator iter_begin = ilist.begin(); iter_begin != ilist.end(); iter_begin++)
	{
		if (*iter_begin % 2 == 0)
		{
			evenDq.push_back(*iter_begin);
		}
		else
		{
			oddDq.push_back(*iter_begin);
		}
	}
	//Êä³öevenDq
	for (deque<int>::iterator iter = evenDq.begin(); iter != evenDq.end(); iter++)
	{
		cout << *iter;
	}
	cout << endl;
	//Êä³öoddDq
	for (deque<int>::iterator iter = oddDq.begin(); iter != oddDq.end(); iter++)
	{
		cout << *iter;
	}
	system("pause");
	return 0;
}