#include <iostream>
#include <string> 
class A {
public:
	A() = delete;
	//A() = default;

	A(int i) {
		this->i = i;
	}

	int i;
};

int main() {
	std::cout << sizeof(A::i) << std::endl;
 
	return 0;
}