#include <iostream>
#include <boost/function.hpp>
#include <algorithm>
#include <boost/bind.hpp>
#include <cstdlib>
#include <functional>


using namespace std;
using namespace boost;



class worker
{
public:
	int id;
	void run(int id)
	{
		this->id = id;
		cout << id << "work" << endl;
	}
protected:
private:
};


class manager
{
public:
	boost::function<void(int)> work;
	void start()
	{
		for (int i = 0; i < 10; i++)
		{
			 if (work)
			 {
				 work(i);
			 }
		}
	}

	void setCallback(boost::function<void(int)> p_work)
	{
		this->work = p_work;
	}

protected:
private:
};




int main2154dg()
{
	manager m;
	worker w;
	//Bind w to run
	m.setCallback(boost::bind(&worker::run, &w, _1));
	 
	m.start();

	system("pause");
	return 0;
}







int main8678658()
{
	boost::function<int(char*)> fun = boost::bind(strcmp, "123123", _1);
	//strcmp == return 0
	//!= return !0
	cout << fun("123123") << endl;
	 

	system("pause");
	return 0;
}




int main45645()
{
	//The function<int(char*)> fun :is a function point
	boost::function<int(char*)> fun = atoi;
	cout << fun("123") << endl;
	fun = strlen;
	cout << fun("123") << endl;
	 
	system("pause");
	return 0;
}