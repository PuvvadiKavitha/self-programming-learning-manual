#include <iostream>
#include <boost/thread.hpp>
#include <cstdlib>



using namespace std;
using namespace boost;


void wait(int sec)
{
	boost::this_thread::sleep(boost::posix_time::seconds(sec));
}


void threadA()
{
	for (int i = 0; i < 10; i++)
	{
		wait(1);
		cout << i << endl;
	}
}


void threadB()
{
	try
	{ 
		for (int i = 0; i < 10; i++)
		{
			wait(1);
			cout << i << endl;
		}
	}
	catch (thread_interrupted& t)
	{
		cout << "Thread B is been interrupted" << endl;
	}
	
}




int maingjg()
{
	boost::thread t(threadB);
	wait(3);
	//Interrupt threadB
	t.interrupt();
	t.join();

	cin.get();
	return 0;
}
