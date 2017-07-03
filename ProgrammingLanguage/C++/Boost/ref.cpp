#include <iostream>
#include <boost/ref.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

void print(std::ostream& os, int i) {
	os << i << std::endl;
}

int main() {
	//cout����Ĭ�ϲ��ɿ���������ʹ��ref�����
	//����ĳЩ�������Ҫ�����������ʱ������ö����޷����п������߿������۹��ߣ���ʱ��Ϳ���ѡ�� boost::ref
	boost::function<void(int)> fun = boost::bind(print, boost::ref(std::cout), _1);
	fun(1);

	return 0;
}
