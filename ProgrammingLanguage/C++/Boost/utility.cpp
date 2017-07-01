#include <iostream>
#include <boost/utility.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits.hpp>

using namespace std;
using namespace boost;
/*
����������ʹ�� BOOST_STATIC_ASSERT ��

�����������ڱ����ڽ�����ֵ

�����͵�Ҫ������ڱ����ڱ�ʾ

����Ҫ�����������ϵ����ͳ�����Ĺ�ϵ���ж���

*/

template<typename T>
class only_compatible_with_integral_types
{
public:
	//��̬����
	BOOST_STATIC_ASSERT(boost::is_integral<T>::value);

};

//��̬�������ں���ģ��
template <int i>
void accepts_values_between_1_and_10()
{
	BOOST_STATIC_ASSERT(i >= 1 && i <= 10);
}


int main546sdf1()
{
	only_compatible_with_integral_types<int> a;
	//only_compatible_with_integral_types<double> a;is_integral�涨ֻ����int����  
	
	//accepts_values_between_1_and_10<11>();1 - 10
	accepts_values_between_1_and_10<1>();

	cin.get();
	return 0;
}