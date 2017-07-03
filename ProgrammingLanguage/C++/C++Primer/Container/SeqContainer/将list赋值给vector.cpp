#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main4ewrw()
{
	//初始化list元素类型为char*
	char* sa[] = { "chengzhi", "jiayu", "hello", "world" };
	list<char *> ilist(sa, sa + 4);
	list<string> ilist_2(sa, sa + 4);
	vector<string> ivec;
	ivec.assign(ilist.begin(), ilist.end());
	cout << "list中的char*类型:";
	for (list<char *>::iterator list_begin = ilist.begin(); list_begin != ilist.end(); list_begin++)
	{
		cout << *list_begin << " ";
	}

	//删除最后元素
	cout << endl << "删除最后一个元素:";
	ilist.pop_back();
	for (list<char *>::iterator list_begin = ilist.begin(); list_begin != ilist.end(); list_begin++)
	{
		cout << *list_begin << " ";
	}

	cout << endl << "删除第一个元素:";
	ilist.pop_front();
	for (list<char *>::iterator list_begin = ilist.begin(); list_begin != ilist.end(); list_begin++)
	{
		cout << *list_begin << " ";
	}
	cout << endl << "删除迭代器范围内的元素:";
	ilist_2.erase(ilist_2.begin(), ilist_2.end());
	for (list<string>::iterator list_begin = ilist_2.begin(); list_begin != ilist_2.end(); list_begin++)
	{
		cout << *list_begin->c_str() << " ";
	}


	cout << endl <<  "输出vector中的string:";
	for (vector<string>::iterator vec_begin = ivec.begin(); vec_begin != ivec.end(); vec_begin++)
	{
		cout << vec_begin->c_str() << " "; 
	}

	cout << endl << "删除全部的元素:";
	ivec.clear();
	if (ivec.empty())
	{
		cout << "ivec is empty!" << endl;
	}


	system("pause");
	return 0;
}
