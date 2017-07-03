#include <iostream>
#include <algorithm>
#include <numeric> 
#include <vector>
using namespace std;
int main654sdfgs()
{
	vector<int> ivec;
	int ival;
	while (cin >> ival)
	{
		ivec.push_back(ival);

	}
	//fill_n(ivec.begin(), ivec.size(), 0);
	fill(ivec.begin(), ivec.end(), 1);
	for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); iter++)
	{
		cout << *iter << " ";
	}  

	system("pause");
	return 0;
}