#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
using namespace std;
int main5465sdfgds()
{
	vector<int> ivec;
	int ival;
	while (cin >> ival)
	{
		ivec.push_back(ival);
	}
	cout << count(ivec.begin(), ivec.end(), 4) << endl;
	cin.clear();//���cin��eof״̬��ʹ�´�������Ȼ��Ч
	list<string> ilist;
	string str;
	string s("chengzhi");
	while (cin >> str)
	{
		ilist.push_back(str);
	}
	cout << count(ilist.begin(), ilist.end(), s) << endl;


	system("pause");
	return 0;
}
