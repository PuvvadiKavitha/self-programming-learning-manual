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
		cout << "��һ��Ԫ�صı�ʾ:"
			<< ivec[0] << " "
			<< ivec.front() << " "
			<< *ivec.begin() << endl;
		cout << "���һ��Ԫ�صı�ʾ:"
			<< ivec.back() << endl;
		cout << "��3��Ԫ�صı�ʾ"
			<< ivec.at(2);
	}
	else
	{
		cout << "vector��û��Ԫ��" << endl;
	}



	system("pause");
	return 0;
}
