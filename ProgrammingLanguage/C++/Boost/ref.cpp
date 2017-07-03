#include <iostream>
#include <boost/ref.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

void print(std::ostream& os, int i) {
	os << i << std::endl;
}

int main() {
	//cout对象默认不可拷贝，可以使用ref来解决
	//当在某些情况下需要拷贝对象参数时，如果该对象无法进行拷贝或者拷贝代价过高，这时候就可以选择 boost::ref
	boost::function<void(int)> fun = boost::bind(print, boost::ref(std::cout), _1);
	fun(1);

	return 0;
}
