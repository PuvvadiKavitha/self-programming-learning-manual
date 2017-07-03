#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric> 
using namespace std;
int main321asfd32f1()
{
	istream_iterator<int> in_iter_begin(cin);
	istream_iterator<int> in_iter_end;
	vector<int> ivec(in_iter_begin, in_iter_end);
	for (vector<int>::iterator it = ivec.begin(); it != ivec.end(); it++)
	{
		cout << *it << " ";
	}
	system("pause");
	return 0;
}
