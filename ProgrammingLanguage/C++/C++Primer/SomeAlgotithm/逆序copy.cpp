#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric> 
#include <list>
#include <iterator>
using namespace std;
int main321fds3gs()
{
	list<int> ilist;
	int ival;
	while (cin >> ival)
	{
		ilist.push_back(ival);
	}

	vector<int> ivec;
	reverse_copy(ilist.begin(), ilist.end(), back_inserter(ivec));
	//vector<int> ivec(5);
	//reverse_copy(ilist.begin(), ilist.end(), ivec.begin());

	for (vector<int>::iterator it = ivec.begin(); it != ivec.end(); it++)
	{
		cout << *it << " ";
	}



	system("pause");
	return 0;
}
