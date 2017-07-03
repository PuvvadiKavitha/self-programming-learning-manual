#include <iostream>
#include <string>
#include <list>
using namespace std;
int main21212512()
{
	list<string> ilist;
	string str;
	while (cin >> str)
	{
		ilist.push_back(str);
	}
	list<string>::iterator iter_begin = ilist.begin();
	while (iter_begin != ilist.end())
	{
		cout << *iter_begin << endl;
		iter_begin++;
	}

	system("pause");
	return 0;
}
