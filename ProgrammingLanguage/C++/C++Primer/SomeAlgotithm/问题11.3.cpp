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

	cout << "�����:" << accumulate(ivec.begin(), ivec.end(), 0) << endl;
	cout << "û�����" << accumulate(ivec.begin(), ivec.end(), 0.0) << endl; 

	system("pause");
	return 0;
}