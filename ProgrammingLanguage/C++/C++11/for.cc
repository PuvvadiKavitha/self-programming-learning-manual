#include <iostream> 

int main() {
	int my_array[5] = { 1, 2, 3, 4, 5 };
	for (int i : my_array)
		std::cout << i << " " << std::endl;
	
	return 0;
}