#include <iostream>
#include <string>
#include "Hash.h"
#include "HashNode.h"
#include "Hash.cpp"
using namespace std;
int main()
{
	Hash<int> my_hash;
	int a[10] = { 10, 11, 22, 33, 44, 55, 56, 67, 78, 99 };
	my_hash.init(a, 10);
	cout << my_hash.isIn(43, 43) << endl;//�Ƿ����43

	HashNode<int>* p = my_hash.find(8);//��������Ϊ8
	cout << p->key << endl;//��ӡ����
	cout << p->t << endl;//��ӡ������ֵ


	system("pause");
	return 0;
}