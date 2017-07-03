#include <iostream>
#include <boost/scoped_ptr.hpp>
#include <boost/scoped_array.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/shared_array.hpp>
#include <boost/weak_ptr.hpp>

//学会boost库的配置

using namespace std;
using namespace boost;

int main()
{
	boost::shared_ptr<int> p(new int(100));
	boost::weak_ptr<int> pw(p);//弱指针常用来观察共享指针，常用于多线程
	boost::shared_ptr<int> px = pw.lock();//锁定内存不被释放，而不是锁定数值不被修改 
	//p.reset();//将指针重置为空，指向的内存被释放, 在锁定弱指针后触发这个函数会出现异常
	*p = 200;
	cout << *p << endl;

	  

	cin.get();
	return 0;
}
 

int maindfs()
{
	//5000 ~ 10000行代码
	boost::shared_ptr<int> p(new int);
	boost::shared_ptr<int> px(p);//共享智能指针可以实现共享一片内存

	boost::shared_array<int> p2(new int[5]);
	boost::shared_array<int> p3(p2);//可以使用拷贝初始化

	cin.get();
	return 0;
} 


int mainafdas()
{
	boost::scoped_array<int> p(new int[5]);//智能管理数组的指针
	p[0] = 1;
	p[1] = 2;
	cout << *p.get() << endl; 
	 
	cin.get();
	return 0;
}





int mainsdfa()
{
	boost::scoped_ptr<int> p(new int);//自动释放内存
	*p = 10;
	cout << &p << endl; //指针自己的地址
	cout << p.get() << endl;//得到指针储存的地址
	cout << *p.get() << endl;//得到指针指向的值
	cout << *p << endl;

	p.reset(new int);//重置指针
	*p = 3;
	cout << p.get() << endl;
	cout << *p.get() << endl;

	int *px = new int(5);
	//p = px;智能指针和普通指针之间不可以直接赋值
	 
	system("pause");
	return 0;
}
