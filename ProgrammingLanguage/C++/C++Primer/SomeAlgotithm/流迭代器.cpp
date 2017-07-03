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
int main65ds4f6dsfg()
{
	istream_iterator<int> cin_it(cin);
	istream_iterator<int> end_of_stream;//超出末端迭代器
	vector<int> ivec(cin_it, end_of_stream);
	sort(ivec.begin(), ivec.end());
	ostream_iterator<int> output(cout, " ");
	unique_copy(ivec.begin(), ivec.end(), output);//取出重复

	system("pause");
	return 0;
}
