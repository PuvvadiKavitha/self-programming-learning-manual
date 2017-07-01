#include <iostream>
#include <boost/tuple/tuple.hpp>
#include <boost/typeof/typeof.hpp>
#include <string>

using namespace std;

boost::tuple<int, string, char, double> return_group()
{
	return boost::make_tuple(1, "123456", 'a', 2.3);
}

int mainwerwrqw()
{
	//BOOST_AUTO(t, boost::make_tuple(1, "123456", "a", 2.3));
	BOOST_AUTO(t, return_group());
	cout << t.get<0>() << endl;
	cout << t.get<1>() << endl;
	cout << t.get<2>() << endl;
	cout << t.get<3>() << endl;
	system("pause");
	return 0;
}
