#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric> 
#include <iterator>

using namespace std;
int mainasdfasd()
{
	int ival;
	vector<int> ivec;
	while (cin >> ival)
	{
		ivec.push_back(ival);
	}
	for (vector<int>::reverse_iterator iter_rbegin = ivec.rbegin(); iter_rbegin != ivec.rend(); iter_rbegin++)
	{
		cout << *iter_rbegin << " ";
	}

	cout << endl << "ÆÕÍ¨µü´úÆ÷ÄæÐòÊä³övector:" << endl;
	for (vector<int>::iterator iter_end = ivec.end(); iter_end != ivec.begin(); iter_end--)
	{
		cout << *(iter_end - 1) << " ";
	}


	system("pause");
	return 0;
}
