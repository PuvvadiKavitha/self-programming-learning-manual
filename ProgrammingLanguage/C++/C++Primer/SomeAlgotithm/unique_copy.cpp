#include <iostream>
#include <algorithm>
#include <numeric> 
#include <list>
#include <vector>
#include <iterator>
using namespace std;
int main321dsfgsd()  
{
	list<int> ilist;
	vector<int> ivec;
	int ival;
	while (cin >> ival)
	{
		ilist.push_back(ival);
	}

	unique_copy(ilist.begin(), ilist.end(), back_inserter(ivec));//����list������ȥ�����е��ظ�Ԫ�أ�ֻ����һ���ظ���Ԫ��
	for (vector<int>::iterator it = ivec.begin(); it != ivec.end(); it++)
	{
		cout << *it << " ";
	}

	system("pause");
	return 0;
}
