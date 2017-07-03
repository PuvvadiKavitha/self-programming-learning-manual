#include <iostream>

constexpr int test() {
	return 5;
}

int main() {
	int buf[test() + 5];
	std::cout << sizeof(buf) << std::endl;
	return 0;
}