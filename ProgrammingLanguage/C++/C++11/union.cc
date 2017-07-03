#include <iostream> 

using namespace std;
class A {
public:
	int i = 10;
	A() { }

	A(int i) {
		this->i = i;
	} 
};

// Don't compile
union {
	int a1;
	double b;
	A a;
};

int main() {
	
	return 0;
}