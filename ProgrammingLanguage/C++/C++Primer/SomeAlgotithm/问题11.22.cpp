#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric> 
#include <list>
using namespace std;
int main5646dfgsdfg()
{
	vector<int> ivec;
	int ival;
	while (cin >> ival)
	{
		ivec.push_back(ival);
	}
	vector<int>::reverse_iterator rbegin = ivec.rbegin() + 3;
	vector<int>::reverse_iterator rend = ivec.rend() - 2;
	list<int> ilist(rbegin, rend);
	for (list<int>::iterator it = ilist.begin(); it != ilist.end(); it++)
	{
		cout << *it << " "; 
	}
	  


	system("pause");
	return 0;
}
