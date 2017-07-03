#include <iostream>
#include <algorithm>
#include <numeric> 
#include <iterator>
#include <list>
using namespace std;

void PrintList(list<int> ilist)
{
	for (list<int>::iterator iter_begin = ilist.begin(); iter_begin != ilist.end(); iter_begin++)
	{
		cout << *iter_begin << " ";
	}
	cout << endl;
}

int main897wer()
{
	list<int> ilist;
	list<int> ilist1;
	list<int> ilist2;
	list<int> ilist3;
	int ival;
	while (cin >> ival)
	{
		ilist.push_back(ival);
	}
	replace_copy(ilist.begin(), ilist.end(), back_inserter(ilist1), 1, 11);
	replace_copy(ilist.begin(), ilist.end(), front_inserter(ilist2), 2, 22);
	replace_copy(ilist.begin(), ilist.end(), inserter(ilist3, ilist3.begin()), 3, 33);
	PrintList(ilist);
	PrintList(ilist1);
	PrintList(ilist2);
	PrintList(ilist3);

	system("pause");
	return 0;
}
