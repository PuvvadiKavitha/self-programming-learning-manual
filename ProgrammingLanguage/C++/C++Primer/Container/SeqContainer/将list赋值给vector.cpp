#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main4ewrw()
{
	//��ʼ��listԪ������Ϊchar*
	char* sa[] = { "chengzhi", "jiayu", "hello", "world" };
	list<char *> ilist(sa, sa + 4);
	list<string> ilist_2(sa, sa + 4);
	vector<string> ivec;
	ivec.assign(ilist.begin(), ilist.end());
	cout << "list�е�char*����:";
	for (list<char *>::iterator list_begin = ilist.begin(); list_begin != ilist.end(); list_begin++)
	{
		cout << *list_begin << " ";
	}

	//ɾ�����Ԫ��
	cout << endl << "ɾ�����һ��Ԫ��:";
	ilist.pop_back();
	for (list<char *>::iterator list_begin = ilist.begin(); list_begin != ilist.end(); list_begin++)
	{
		cout << *list_begin << " ";
	}

	cout << endl << "ɾ����һ��Ԫ��:";
	ilist.pop_front();
	for (list<char *>::iterator list_begin = ilist.begin(); list_begin != ilist.end(); list_begin++)
	{
		cout << *list_begin << " ";
	}
	cout << endl << "ɾ����������Χ�ڵ�Ԫ��:";
	ilist_2.erase(ilist_2.begin(), ilist_2.end());
	for (list<string>::iterator list_begin = ilist_2.begin(); list_begin != ilist_2.end(); list_begin++)
	{
		cout << *list_begin->c_str() << " ";
	}


	cout << endl <<  "���vector�е�string:";
	for (vector<string>::iterator vec_begin = ivec.begin(); vec_begin != ivec.end(); vec_begin++)
	{
		cout << vec_begin->c_str() << " "; 
	}

	cout << endl << "ɾ��ȫ����Ԫ��:";
	ivec.clear();
	if (ivec.empty())
	{
		cout << "ivec is empty!" << endl;
	}


	system("pause");
	return 0;
}
