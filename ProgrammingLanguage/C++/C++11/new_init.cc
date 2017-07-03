#include <iostream> 

class A {
public:
	std::string name;
	int id; 
};

int main() {
	A a { "tom", 4 };
	A a1 = { "tom", 4 };
	return 0;
}