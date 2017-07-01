#include <iostream>
#include <boost/checked_delete.hpp>
using namespace std;
using namespace boost;

//checked_delete的实现
template <typename T>
inline void my_checked_delete(T* t)
{
	/*
	这里的想法是创建一个char的数组，数组的元素数量为T的大小。
	如果 checked_delete 被一个不完整的类型 T 所实例化，编译将会失败，
	因为 sizeof(T) 会返回 0, 而创建一个0个元素的(自动)数组是非法的。
	*/
	typedef char type_must_be_complete[sizeof(T)];

	//也可以用 BOOST_STATIC_ASSERT 来执行这个断言
	//BOOST_STATIC_ASSERT(sizeof(T));
	delete t;
}


class some_class;
/*
删除一个动态分配的对象时，必须调用它的析构函数。
如果这个类型是不完整的，即只有声明没有定义，那么析构函数可能会没被调用。
这是一种潜在的危险状态，所以应该避免它
*/
//不完整的类型是指已声明但未定义的类型。
some_class* create()
{
	return (some_class*)0;
}

int mainwerwerwq()
{
	some_class* p = create();
	//boost::checked_delete(p);
	//my_checked_delete(p);
	system("pause");
	return 0;
}