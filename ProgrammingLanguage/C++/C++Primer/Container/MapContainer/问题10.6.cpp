#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>
using namespace std;
int main231hfd()
{
	map<string, vector<int> >map1;
	string str;
	//指向元素的迭代器
	map<string, vector<int> >::iterator iter = map1.find(str);
	//元素是否存在
	cout << map1.count(str) << endl;

	system("pause");
	return 0;
}