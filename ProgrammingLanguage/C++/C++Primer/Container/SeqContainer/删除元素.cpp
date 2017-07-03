#include <iostream>
#include <vector>
#include <list>
using namespace std;
int main321fdgh()
{
	//初始化list和vector 
	int ia[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	list<int> ilist(ia, ia + 10);
	vector<int> ivec(ia, ia + 10);
	
	//遍历list, 删除奇数
	for (list<int>::iterator list_begin = ilist.begin(); list_begin != ilist.end(); list_begin++)
	{
		if (*list_begin % 2 != 0)
		{
			list_begin = ilist.erase(list_begin);
			list_begin--;
		}
	}

	//遍历vec, 删除偶数
	for (vector<int>::iterator vector_begin = ivec.begin(); vector_begin != ivec.end(); vector_begin++)
	{
		if (*vector_begin % 2 == 0)
		{
			vector_begin = ivec.erase(vector_begin);
			vector_begin--;
		}
	}

	//输出list
	cout << "list:" << endl;
	list<int>::iterator ilist_begin = ilist.begin();
	while (ilist_begin != ilist.end())
	{
		cout << *ilist_begin << " ";
		ilist_begin++;
	} 

	//输出vector
	cout << "vector:" << endl;
	vector<int>::iterator ivec_begin = ivec.begin();
	while (ivec_begin != ivec.end())
	{
		cout << *ivec_begin << " ";
		ivec_begin++;
	}

	system("pause");
	return 0;
}
