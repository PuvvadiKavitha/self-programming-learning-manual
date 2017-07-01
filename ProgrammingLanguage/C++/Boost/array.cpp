#include <iostream>
#include <boost/array.hpp>


int main() {
	
	boost::array<int, 5> a = { 1, 2, 3, 4, 5 };
	
	// Modify
	a[0] = 10;
	a.at(4) = 50;

	// Use point to array is ok, but must in array`s member function : data()
	int *px = a.data();

	for (int i = 0; i < a.size(); i++)
		std::cout << px[i] << " " << a[i] << std::endl;
	
	//string array
	boost::array<std::string, 5> b = { "calc", "notepad", "tasklist", "write", "dir" };
	for (int i = 0; i < b.size(); i++)
		std::cout << b[i] << std::endl;

	return 0;
}
