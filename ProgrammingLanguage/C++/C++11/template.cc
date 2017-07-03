#include <iostream>
#include <vector>

// Don't let compile instance vector in this mode.
extern template class vector<int>;

int main() {
	std::vector<char> v;

	return 0;
}