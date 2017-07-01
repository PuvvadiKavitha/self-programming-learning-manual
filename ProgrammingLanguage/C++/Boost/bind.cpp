#include <iostream>
#include <boost/bind.hpp>
#include <vector>
#include <functional>
#include <algorithm>


//1. To inherit binary_function<int, int, void>
//2. Need the function : type cast function
class add : public boost::binary_function<int, int, void> {
public:
	void operator ()(int x, int y) const {
		cout << x + y << " ";
	}
};


void addx(int x, int y)
{
	cout << x + y << " ";
}

int main() {
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	
	//Bind1st need the class add:

	cout << "No use the boost bind:" << endl;
	for_each(vec.begin(), vec.end(), bind1st(add(), 10));

	cout << endl << "Use the boost bind:" << endl;
	// Bind parament to function need boost lib
	for_each(vec.begin(), vec.end(), bind(addx, 10, _1));

	return 0;
}
