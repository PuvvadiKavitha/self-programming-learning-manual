#include <iostream>
#include <algorithm>
#include <numeric> 
#include <iterator>
#include <vector>

using namespace std;
int main()
{
	vector<int> myvec;
	myvec.push_back(1);
	myvec.push_back(2);
	myvec.push_back(3);
	myvec.push_back(4);
	myvec.push_back(5);

	//������ָ���λ�ò��ܸı�, ֻ��ָ��һ��λ��
	//ָ���λ�õ�Ԫ�ص�ֵ���Ըı�
	const vector<int>::iterator it = myvec.begin();
	*it = 1111;
	//it = myvec.end();

	//������ָ���λ�ÿ��Ըı䵫��ָ���λ�õ�ֵ���ܸı�
	//���õ�������ֻ��������
	vector<int>::const_iterator c_it = myvec.begin();
	c_it = myvec.end();
	//*c_it = 11;



	system("pause");
	return 0;
}
