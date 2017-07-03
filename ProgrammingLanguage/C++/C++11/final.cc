#include <iostream>
 
class myclass {
public:
	virtual void run()  { 
		std:: cout << "myclass run" << std::endl;
	}
	
	// Didn't override
	virtual void go() final  {
		std:: cout << "myclass go" << std::endl;
	}

};

class runit : public myclass {
public:
	void run() override {
		std:: cout << "runit run" << std::endl;
	}
	/*
	// Error
 	void go() override{
 		std:: cout << "runit go" << std::endl;
 	}
 	*/
};

int main() {
	myclass *p = new runit;
	p->run();
	p->go();
	return 0;
}