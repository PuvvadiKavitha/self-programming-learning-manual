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

	unique_copy(ilist.begin(), ilist.end(), back_inserter(ivec));//复制list，但是去掉其中的重复元素，只保留一个重复的元素
	for (vector<int>::iterator it = ivec.begin(); it != ivec.end(); it++)
	{
		cout << *it << " ";
	}

	system("pause");
	return 0;
}
