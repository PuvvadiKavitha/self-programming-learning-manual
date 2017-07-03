#include <iostream>
#include <algorithm>
#include <numeric> 
#include <iterator>
#include <vector>
using namespace std;
int main23423645()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	reverse_iterator<vector<int>::iterator> it_begin(v.end());
	reverse_iterator<vector<int>::iterator> it_end(v.begin());

	copy(it_begin, it_end, ostream_iterator<int>(cout, " "));





	system("pause");
	return 0;
}