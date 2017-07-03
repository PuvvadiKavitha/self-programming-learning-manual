#include <iostream>
#include <boost/unordered_set.hpp>
#include <string> 

int main() {
	 
	boost::unordered_set<std::string> hashset;
	hashset.insert("c");
	hashset.insert("d");
	hashset.insert("e");
	hashset.insert("a");
	hashset.insert("b");

	for (auto ib = hashset.begin(); ib != hashset.end(); ib++)
	
		std::cout << *ib << std::endl;
	

	std::cout << (hashset.find("a") != hashset.end()) << std::endl;
 
	return 0;
}