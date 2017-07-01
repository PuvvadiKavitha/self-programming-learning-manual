#include <iostream>
#include <boost/utility.hpp>


//当你需要获得一个对象的真实地址时，使用 addressof ，不必管 operator& 的语义。
using namespace std;
using namespace boost;

class my_class
{
public:
	int operator &() const
	{
		return 10;
	}
protected:
private:
};

int mainr757456()
{
	my_class s;
	//获取对象的真实地址，即使类重载了&仍然有效
	cout << &s << endl;
	cout << boost::addressof(s) << endl;

	system("pause");
	return 0;
}