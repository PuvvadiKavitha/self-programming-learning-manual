#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <list>
#include <map>
using namespace std;
int main65fs()
{
	map<vector<int>::iterator, int> map1;
	map<pair<int, string>, int> map2;
	map<list<int>::iterator, int> map3;//list的迭代器不支持<号操作

	map<int, string> map4;
	string str;
	map<int, string>::iterator iter = map4.begin();
	iter->second = str;
	//iter->first = 1;
	system("pause");
	return 0;
}
