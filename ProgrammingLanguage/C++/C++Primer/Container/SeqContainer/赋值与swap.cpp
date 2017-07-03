#include <iostream>
#include <vector>
using namespace std;
int main3s1dfasdf()
{
	vector<int> ivec1(5, 1);
	vector<int> ivec2(5, 2);
	ivec2.assign(5, 3);
	ivec1.swap(ivec2);
	vector<int>::iterator ivec1_begin = ivec1.begin();
	vector<int>::iterator ivec2_begin = ivec2.begin();
	while (ivec1_begin != ivec1.end())
	{
		cout << *ivec1_begin << " ";
		ivec1_begin++;
	}
	cout << endl;
	while (ivec2_begin != ivec2.end())
	{
		cout << *ivec2_begin << " ";
		ivec2_begin++;
	}





	system("pause");
	return 0;
}
