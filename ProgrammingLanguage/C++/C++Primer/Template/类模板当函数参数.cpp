#include <iostream>
#include <array>
using namespace std;

template<typename T, int n>
void fun(array<T, n> ar)//����ģ������ĺ�����һ���Ǻ���ģ��
{
	for (auto &i : ar)
	{
		i += 1;
		
	}
	for (auto i : ar)
	{
		cout << i << endl;
	}

}



int main12312()
{
	array<int, 5> ar = {1, 2, 3, 4, 5};
	fun<int, 5>(ar);//����淶����������ͣ�������
	//����ģ�����ݲ����Զ�����
	system("pause");
	return 0;
}
