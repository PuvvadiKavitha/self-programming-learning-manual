#include<iostream>

using namespace std;

//必须会：类成员函数指针，类成员二级函数指针，类成员函数指针数组


//作业：使用类成员函数指针
//0-100
//上下左左右，移动，放大缩小

class op
{
public:
	op(int x, int y) :a(x), b(y)
	{

	}
	int add(int a, int b)
	{
		return a + b;
	}
	int mul(int a, int b)
	{
		return a * b;
	}
	int divv(int a, int b)
	{
		return a / b;
	}
	int sub(int a, int b)
	{
		return a - b;
	}
private:
	int a;
	int b;
};




void main121212()
{
	op op1(100, 10);
	auto fun1 = &op::add;//fun1无法调用
	cout << typeid(fun1).name() << endl;//打印add的类型
	int(op::*p)(int, int) = &op::add;//创建类成员函数指针，指定对象来调用
	cout << (op1.*p)(40, 50) << endl;//调用方式,类成员函数传递this指针，也就是对象地址
	//类成员函数指针必须通过类对象来调用 
	cin.get();

}


void main()
{

	op op1(100, 10);

	//类成员函数指针数组p   p是一个二级指针
	int(op::*p[4])(int a, int b) = { &op::add, &op::sub, &op::mul, &op::divv};

	//下标访问
	for (int i = 0; i < 4;i++)
	{ 
		cout << (op1.*p[i])(500, 50) << endl; //p[i]是一个类成员函数指针
	}
	 
	//遍历一个指针数组需要一个二级指针
	//int(op::**pp)(int a, int b)二级类成员函数指针
	
	for (int(op::**pp)(int a, int b) = p; pp < p + 4; pp++)
	{ 
		cout <<  (op1.**pp)(500, 50) << endl;//**pp是类成员函数指针
	}

	cin.get();
}