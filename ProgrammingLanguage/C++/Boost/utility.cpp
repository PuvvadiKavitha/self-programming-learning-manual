#include <iostream>
#include <boost/utility.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits.hpp>

using namespace std;
using namespace boost;
/*
以下情形下使用 BOOST_STATIC_ASSERT ：

当条件可以在编译期进行求值

对类型的要求可以在编译期表示

你需要对两个或以上的整型常量间的关系进行断言

*/

template<typename T>
class only_compatible_with_integral_types
{
public:
	//静态断言
	BOOST_STATIC_ASSERT(boost::is_integral<T>::value);

};

//静态断言用于函数模板
template <int i>
void accepts_values_between_1_and_10()
{
	BOOST_STATIC_ASSERT(i >= 1 && i <= 10);
}


int main546sdf1()
{
	only_compatible_with_integral_types<int> a;
	//only_compatible_with_integral_types<double> a;is_integral规定只能是int类型  
	
	//accepts_values_between_1_and_10<11>();1 - 10
	accepts_values_between_1_and_10<1>();

	cin.get();
	return 0;
}