#include <iostream>
#include <boost/utility.hpp>

//boost::noncopyable 的工作原理就是禁止访问它的复制构造函数和赋值操作符，然后使用它作为基类。
//另一种方法是：复制构造函数和赋值操作符声明为私有的或是保护的并增加一个缺省构造函数(因为编译器不再自动生成它了)。
using namespace std;
using namespace boost;

class please_no_copy : boost::noncopyable
{

};

/*
一个类的the big three：
复制构造函数、(虚拟)析构函数、和赋值操作符，中的任何一个被手工定义，
在决定不需要定义其余两个之前必须认真仔细地考虑清楚。
还有，如果你不想要复制，记得使用 boost::noncopyable ！

*/



/*
以下情形下使用 noncopyable ：

类型的复制和赋值都不被允许

复制和赋值的禁止应该尽可能明显



*/


int main6541321()
{
	//不能通过编译。由于noncopyable的复制构造函数是私有的，因此对d2进行复制构造的尝试会失败
	please_no_copy p;
	//please_no_copy p2(p);
	//please_no_copy p3 = p;

	system("pause");
	return 0;
}