#include <iostream>
#include <string>
#include <algorithm>
#include <vector> 

int main() {
	std::vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	int total = 0;
	
	std::for_each(a.begin(), a.end(), [&total](int x) {
		total += x; 
		std::cout << total << " " << std::endl;
	});

	return 0;
}