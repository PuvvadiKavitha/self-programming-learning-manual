#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main32132qweqwe()
{
	int ival;
	//输入list元素
	cout << "输入list元素:";
	list<int> ilist;
	while (cin >> ival)
	{
		ilist.push_back(ival);
	}

	//list的输入使用了文件结束符eof,为了cin的下一次输入，需要重置cin为有效
	cin.clear();

	//输入vector元素
	vector<int> ivec;
	cout << "输入vetor元素:";
	while (cin >> ival)
	{
		ivec.push_back(ival);
	}  

	//迭代判断是否相等
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

	//判断结果
    if (list_begin == ilist.end() && vector_begin == ivec.end())
    {
		cout << "list和vector中的元素相等" << endl;
    }
	else
	{
		cout << "list和vector中的元素不相等" << endl;
	}
 
	system("pause");
	return 0;
}
