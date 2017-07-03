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
int main46dsfg4ds()
{
	list<int> ilist;
	int ival;
	while (cin >> ival)
	{
		ilist.push_back(ival);
	}

	list<int>::reverse_iterator it = find(ilist.rbegin(), ilist.rend(), 0);
	cout << *it << endl;
	system("pause");
	return 0;
}
