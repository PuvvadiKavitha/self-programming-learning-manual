#include <iostream>
#include <vector>
using namespace std;
int main3213sd2afsd()
{
	int ival;
	vector<int> ivec;
	while (cin >> ival)
	{
		ivec.push_back(ival);
	}

	if (ivec.empty() == false)
	{
		cout << "第一个元素的表示:"
			<< ivec[0] << " "
			<< ivec.front() << " "
			<< *ivec.begin() << endl;
		cout << "最后一个元素的表示:"
			<< ivec.back() << endl;
		cout << "第3个元素的表示"
			<< ivec.at(2);
	}
	else
	{
		cout << "vector中没有元素" << endl;
	}



	system("pause");
	return 0;
}
