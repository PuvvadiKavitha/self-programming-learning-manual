#include <iostream>
#include <list>
#include <string>
using namespace std;
int main231dsfawr()
{
	list<string> ilist;
	string str;
	cout << "����list:";
	while (cin >> str)
	{
		ilist.push_back(str);
	}
	cin.clear();

	cout << "����str:";
	cin >> str;
	list<string>::iterator iter_begin;
	for (iter_begin = ilist.begin(); iter_begin != ilist.end(); iter_begin++)
	{
		if (*iter_begin == str)
		{
			iter_begin = ilist.erase(iter_begin);
			iter_begin--;
		}
	}
	cout << "���ɾ��Ԫ�غ�list:" << endl;
	iter_begin = ilist.begin();
	while (iter_begin != ilist.end())
	{
		cout << *iter_begin << " ";
		iter_begin++;
	}



	system("pause");
	return 0;
}
