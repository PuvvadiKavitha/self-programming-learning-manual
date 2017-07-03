#include <iostream>
#include <string>
#include <tuple> 

typedef std::tuple<int, char, const char*> mytuple;

int main() {
	int i = 10;
	char c = 'a';
	const char* s = "Hello World";
	
	mytuple a(i, c, s);
	
	std::cout << std::get<0>(a) << std::endl;
	std::cout << std::get<1>(a) << std::endl;
	std::cout << std::get<2>(a) << std::endl;
 
	return 0;
}