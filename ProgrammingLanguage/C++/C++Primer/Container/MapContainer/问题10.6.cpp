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
	//ָ��Ԫ�صĵ�����
	map<string, vector<int> >::iterator iter = map1.find(str);
	//Ԫ���Ƿ����
	cout << map1.count(str) << endl;

	system("pause");
	return 0;
}