#include <iostream>
#include <boost/function.hpp>
#include <algorithm>
#include <boost/bind.hpp>
#include <cstdlib>
#include <functional>


class worker {
public:
	int id;
	void run(int id) {
		this->id = id;
		cout << id << "work" << endl;
	}
};


class manager {
public:
	boost::function<void(int)> work;
	void start() {
		for (int i = 0; i < 10; i++) {
			 if (work)
				 work(i);
		}
	}

	void setCallback(boost::function<void(int)> p_work)
	{
		this->work = p_work;
	}
};




int main() {
	manager m;
	worker w;
	// Bind w to m
	m.setCallback(boost::bind(&worker::run, &w, _1));
	 
	m.start();

	return 0;
}


int main1() {
	boost::function<int(char*)> fun = boost::bind(strcmp, "123123", _1);
	std::cout << fun("123123") << std::endl;
	return 0;
}




int main2() {
	// The function<int(char*)> fun is a function point.
	boost::function<int(char*)> fun = atoi;	
	std::cout << fun("123") << std::endl;

	fun = strlen;
	std::cout << fun("123") << std::endl;
	 
	return 0;
}
