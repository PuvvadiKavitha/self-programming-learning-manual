#include <iostream>
#include <boost/unordered_set.hpp>
#include <string>


using namespace std;
using namespace boost;

int main1231rrty()
{
	//��C++�ײ��ʵ�ֻ��Ʋ�ͬ���ĺ����Ϊ��ϣ��ʵ��
	boost::unordered_set<string> hashset;
	hashset.insert("c");
	hashset.insert("d");
	hashset.insert("e");
	hashset.insert("a");
	hashset.insert("b");
	
	for (auto ib = hashset.begin(); ib != hashset.end(); ib++)
	{
		cout << *ib << endl;
	}

	cout << (hashset.find("a") != hashset.end()) << endl;



	system("pause");
	return 0;
}
