#include <iostream>
#include <boost/ref.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

using namespace std;
using namespace boost;

void print(ostream& os, int i)
{
	os << i << endl;
}

int main456456()
{
	//cout����Ĭ�ϲ��ɿ���������ʹ��ref�����
	//����ĳЩ�������Ҫ�����������ʱ������ö����޷����п���
	//���߿������۹��ߣ���ʱ��Ϳ���ѡ��ref
	boost::function<void(int)> fun = boost::bind(print, boost::ref(cout), _1);
	fun(1);


	system("pause");
	return 0;
}
