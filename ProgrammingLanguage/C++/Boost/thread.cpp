#include <iostream>
#include <boost/thread.hpp>
#include <cstdlib>


void wait(int sec) {
	boost::this_thread::sleep(boost::posix_time::seconds(sec));
}


void threadA() {
	for (int i = 0; i < 10; i++) {
		wait(1);
		std::cout << i << std::endl;
	}
}


void threadB() {
	try { 
		for (int i = 0; i < 10; i++) {
			wait(1);
		    std::cout << i << std::endl;
		}
	} catch (boost::thread_interrupted& t) {
		std::cout << "Thread B is been interrupted" << std::endl;
	}
	
}


int main() {
	boost::thread t(threadB);
	wait(3);
	
	// Interrupt threadB
	t.interrupt();
	
	t.join();

	return 0;
}
