#include <iostream>
#include <boost/utility.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits.hpp>

/*
	����������ʹ�� BOOST_STATIC_ASSERT :
	1. �����������ڱ����ڽ�����ֵ
	2. �����͵�Ҫ������ڱ����ڱ�ʾ
	3. ��Ҫ�����������ϵ����ͳ�����Ĺ�ϵ���ж���
*/

template<typename T>
class only_compatible_with_integral_types {
public:
	//��̬����
	BOOST_STATIC_ASSERT(boost::is_integral<T>::value);
};

template <int i>
void accepts_values_between_1_and_10() {
	BOOST_STATIC_ASSERT(i >= 1 && i <= 10);
}


int main() {
	//only_compatible_with_integral_types<int> a;
	only_compatible_with_integral_types<double> a;
	
	accepts_values_between_1_and_10<11>();1 - 10
	//accepts_values_between_1_and_10<1>();
	return 0;
}
