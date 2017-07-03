#include <iostream>
#include <typeinfo>
//rtti,实时类型检测
//typeid,  dynamic_cast必须依赖于虚函数表
//转换多态最好使用dynamic_cast转换
//类型不匹配转换失败，返回为空,保证安全

//总结
/*
static_cast:常规的转换
reinterpret_cast:指针之间的转换
dynamic_cast:多态之间的转换
const_cast:取出const属性的转换
*/

/*typeid
只有当typeid的操作数是带有虚函数的类类型的对象的时候，
才能返回动态类型信息，测试指针返回指针的静态的，编译时类型
typeid(p);返回type_info类的引用
*/


//下面的必须掌握
 
using namespace std;
class A
{
public:
	int num;
	static int data;
	virtual  void run()//虚函数--虚函数表
	{
		std::cout << "Arun\n";
		
	}
};
int A::data = 1;



class B :public A
{
public:
	int num = 0;
	static int data;
	void run()
	{
		std::cout << "Brun\n";
	}
	void test()
	{
		std::cout << num << "\n";
		std::cout << "Btest\n";
	}
};
int B::data = 2;


void main231546()
{
	A a1;
	A* p1 = &a1;
	p1 = nullptr;
	try
	{
	     typeid(*p1);//p1 is nullptr
	}
	catch (bad_typeid e)//if p1 is nullptr and p1`s type is virtual then typeid(*p1) will throw "bad_typeid" exception
	{ 
		cout << "bad_typeid" << endl;
	} 
	
	
	std::cin.get();
}

void main4543()
{

	A a1;
	B b1;
	A *p1 = &a1;
	A *p2 = &b1;
	B *p3(nullptr);
	//p3 = static_cast<B *>(p1);//常规的转换-直接赋地址，不安全，与虚函数无关,有没有对象都可以
	p3 = reinterpret_cast<B*>(p2);//指针之间的转换
	//p3 = static_cast<B *>(p2);
	
	std::cout << p3 << "\n";
	p3->test();
	 
	std::cin.get();
}

void main12313()
{

	A a1;
	B b1;
	A& p1 = a1;
	A& p2 = b1;
	B p3;
	B& pp3 = p3;
	try
	{
		p3 = dynamic_cast<B&>(p1);//引用转换失败会抛出bad_cast异常，该异常在typeinfo头文件中定义
	}
	catch (bad_cast b)
	{
		cout << "bad cast" << endl;
	}
	  
 
	std::cin.get();
}

void main231asa3()
{

	A a1;
	B b1;
	A *p1 = &a1;
	A *p2 = &b1;
	B *p3(nullptr);
	p3 = dynamic_cast<B*>(p2);//多态之间的转换---安全 
	//dynamic必须要有虚函数，是根据虚函数表转换，不能转换
	//转换失败为空(自身的特点所决定的),转换成功就是地址
	//类的空指针可以调用不调用数据的函数
	 
	std::cout << p3 << "\n";
	p3->test();


	/*规范写法
	if (p3 = dynamic_cast<B*>(p2))
	{
	std::cout << p3 << "\n";
	p3->test();
	}*/
	 
	std::cin.get();
}
//实时类型检测RTTI

void mainasdas()
{
	
// 	A *p1 = new A;
// 	A *p2 = new B;
	A a1;
	B b1;
	A *p1 = &a1;
	A *p2 = &b1;
	//typeid不能动态获取类型
	//但是A类有虚函数的时候就有虚函数表，typeid就可以获取类型
	//虚函数表可以确定数据类型
	//A类有没有虚函数，下面的输出是不同的。
	
	std::cout << typeid(p1).name() << "  " << typeid(p2).name() << std::endl;
	std::cout << (typeid(p1) == typeid(p2)) << "\n";

	std::cout << typeid(*p1).name() << "  " << typeid(*p2).name() << std::endl;
	std::cout << (typeid(*p1) == typeid(*p2)) << "\n";//重载的方式判定类型是否一致



	std::cin.get();

}

void main22()
{
	B b1;
	b1.num = 10;//成员变量的覆盖, 静态变量也会覆盖
	b1.A::num = 20;
	std::cout << b1.num << "\n" << b1.A::num
		<< std::endl;
	std::cout << b1.data << "   " << b1.A::data << "\n";
	std::cout << &b1.data << "   " << &b1.A::data << "\n";

	std::cin.get();

}