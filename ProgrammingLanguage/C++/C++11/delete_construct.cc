#include <iostream>

class A1 {
public:
	// delete default construct
	//A1() = delete; 
	
	// set using default construct
	A1() = default;
	
	A1(int i) {
		this->i = i;
	}

	int i;
};
 

int main() {
	A1 a1;
	//A1 a1(1);
	return 0;
}