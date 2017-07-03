#include <iostream> 

class A {
public:
	A() : A(20) { }
	
	A(int i) {
		id = i;
	}

	int id = 10;
};

int main() {
	A a;
	// 20
	std::cout << a.id << std::endl;
	return 0;
}