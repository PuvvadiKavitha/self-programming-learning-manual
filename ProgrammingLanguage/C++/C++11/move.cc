#include <iostream>
#include <string> 


class A1
{

};


/*
 * move 的功能就是将一个左值强制转化为一个右值引用。
 * 如果一个对象明确被其他对象引用后便不再使用，那么可以采用浅拷贝方式实现其拷贝构造函数，
 * 浅拷贝完成后将其指针成员赋 NULL
*/
int main1() {
	A1 a;

	// Convert a to right value.
	A1&& b = std::move(a);

	return 0;
}


/*
 * left value has memory location
 * right value don't has memory location
*/
int main() {
	int i = 10;
	int a = 4;
	int b = 3;
	i = a + b;
	
	// a is a left value.
	std::cout << &a << std::endl;
	// 10 is a right value.

	//std::cout << &10 << std::endl;  
	
	return 0;
}