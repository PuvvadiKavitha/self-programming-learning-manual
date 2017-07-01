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
	//cout对象默认不可拷贝，可以使用ref来解决
	//当在某些情况下需要拷贝对象参数时，如果该对象无法进行拷贝
	//或者拷贝代价过高，这时候就可以选择ref
	boost::function<void(int)> fun = boost::bind(print, boost::ref(cout), _1);
	fun(1);


	system("pause");
	return 0;
}
