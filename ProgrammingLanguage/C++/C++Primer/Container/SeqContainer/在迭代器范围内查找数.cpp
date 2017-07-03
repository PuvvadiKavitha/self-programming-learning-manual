#include <iostream>
#include <vector>
using namespace std;

bool Fun(vector<int>::iterator begin, vector<int>::iterator end, int num)
{//本算法在vector中查找num，找到返回true，否则返回false
	while (begin != end)
	{
		if (num == *begin)
		{
			return true;
		}
		begin++;
	}
	return false;
}

vector<int>::iterator Fun_2(vector<int>::iterator begin, vector<int>::iterator end, int num)
{//本算法在vector中查找num，找到返回指向num的begin迭代器，否则返回end迭代器
	while (begin != end)
	{
		if (num == *begin)
		{
			break;
		}
		begin++;
	}
	return begin;
}

template<typename T1, typename T2>
T1 Fun_3(T1 begin, T1 end, T2 val)
{//本方法利用函数模板来查找begin和end之间的数num, T1代表迭代器类型, T2代表要查找的数的类型
//找到返回指向这个数的迭代器, 没找到返回end迭代器
	while (begin != end)

	{
		if (*begin == val)
		{
			break;
		}
		begin++;
	}
	return begin;
}


int main32sadfsd()
{
	int ia[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> ivec(ia, ia + 8);
	vector<int>::iterator iter_begin = ivec.begin();
	vector<int>::iterator iter_end = ivec.end();
	cout << Fun(iter_begin, iter_end, 4) << endl; 
	cout << *Fun_2(iter_begin, iter_end, 4) << endl;
	cout << *Fun_3(iter_begin, iter_end, 4) << endl;
	system("pause");
	return 0;
}
