#include <iostream>
#include <boost/utility.hpp>

/*
	boost::noncopyable 的工作原理就是禁止访问它的复制构造函数和赋值操作符，然后使用它作为基类。
	另一种方法是：复制构造函数和赋值操作符声明为私有的或是保护的并增加一个缺省构造函数(因为编译器不再自动生成它了)。
 */
class please_no_copy : boost::noncopyable
{

};


/*
	以下情形下使用 noncopyable :
	1. 类型的复制和赋值都不被允许
	2. 复制和赋值的禁止应该尽可能明显
*/
int main() {
	// p don't allow copy to other!
	please_no_copy p;
	//please_no_copy p2(p);
	//please_no_copy p3 = p;

	return 0;
}
