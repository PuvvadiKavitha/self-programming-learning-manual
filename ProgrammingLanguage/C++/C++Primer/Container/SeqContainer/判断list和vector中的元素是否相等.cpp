#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main32132qweqwe()
{
	int ival;
	//����listԪ��
	cout << "����listԪ��:";
	list<int> ilist;
	while (cin >> ival)
	{
		ilist.push_back(ival);
	}

	//list������ʹ�����ļ�������eof,Ϊ��cin����һ�����룬��Ҫ����cinΪ��Ч
	cin.clear();

	//����vectorԪ��
	vector<int> ivec;
	cout << "����vetorԪ��:";
	while (cin >> ival)
	{
		ivec.push_back(ival);
	}  

	//�����ж��Ƿ����
	list<int>::iterator list_begin = ilist.begin();
	vector<int>::iterator vector_begin = ivec.begin();
	while (list_begin != ilist.end() && vector_begin != ivec.end())
	{
		if (*list_begin != *vector_begin)
		{
			break;
		}
		list_begin++;
		vector_begin++;
	}

	//�жϽ��
    if (list_begin == ilist.end() && vector_begin == ivec.end())
    {
		cout << "list��vector�е�Ԫ�����" << endl;
    }
	else
	{
		cout << "list��vector�е�Ԫ�ز����" << endl;
	}
 
	system("pause");
	return 0;
}
