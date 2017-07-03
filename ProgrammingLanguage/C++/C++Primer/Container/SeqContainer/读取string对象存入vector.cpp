#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main12313asd()
{
	string str;
	vector<string> ivec;
	while (cin >> str)
	{
		ivec.push_back(str);
	}

	vector<string>::iterator iter_begin = ivec.begin();
	while (iter_begin != ivec.end())
	{
		cout << *iter_begin << endl;
		iter_begin++;
	}



	system("pause");
	return 0;
}