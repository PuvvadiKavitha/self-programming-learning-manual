#include <iostream> 
#include <typeinfo>

int main() { 
	//auto x = 'a';	// type: c
	//auto x = 1;	// type: i
	auto x = 1.0;	// type: d
	
	// y's type = x's type
	decltype(x) y;

	std::cout << "x type: "<< typeid(decltype(x)).name() << std::endl;
	std::cout << "y type: "<< typeid(decltype(y)).name() << std::endl;
	return 0;
}