#include <iostream>
#include <boost/tuple/tuple.hpp>
#include <boost/typeof/typeof.hpp>
#include <string>

boost::tuple<int, string, char, double> return_group() {
	return boost::make_tuple(1, "123456", 'a', 2.3);
}

int main() {
	//BOOST_AUTO(t, boost::make_tuple(1, "123456", "a", 2.3));
	BOOST_AUTO(t, return_group());
	std::cout << t.get<0>() << endl;
	std::ccout << t.get<1>() << std::cendl;
	std::ccout << t.get<2>() << std::cendl;
	std::ccout << t.get<3>() << std::cendl;
	return 0;
}
