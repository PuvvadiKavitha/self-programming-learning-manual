#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
int main321ADS()
{
	vector<double> ivec;
	double ival;
	while (cin >> ival)
	{
		ivec.push_back(ival);
	}

	cout << "ÓÐÎó²î:" << accumulate(ivec.begin(), ivec.end(), 0) << endl;
	cout << "Ã»ÓÐÎó²î" << accumulate(ivec.begin(), ivec.end(), 0.0) << endl; 

	system("pause");
	return 0;
}