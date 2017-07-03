#include <iostream>
#include <boost/utility.hpp>


class my_class {
public:
	int operator &() const {
		return 10;
	}
};

int main() {
	my_class s;
	// Get address, if class has operator(), then call operator()
	std::cout << &s << std::endl;
	// Return real address£¬ignore operator()
	std::cout << boost::addressof(s) << std::endl;

	return 0;
}
