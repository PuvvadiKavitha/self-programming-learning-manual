#include <iostream>

using namespace std;


class Person2
{
public:
	void test()
	{
		cout << "Person2" << endl;
	}
protected:
private:
};


class Person111;//class declaration

//class;class keyword
class Person
{//class scope类作用域
public://access label
	friend class Person2;//可以放在类中的任何地方
	friend void Person2::test();
	friend void Fun(const Person &p);



	Person(const string &p_name, const string &p_address)
		: name(p_name), address(p_address), count(0)//constructor initializer list
	{}
	Person(){}//Always have the default constructor
	explicit Person(const int &p_age)//explicit constructor//显式
	{
		age = p_age;
	}
	void testCount() const;
	string getName() const//const member function
	{
		return this->name;
	}
	string getAddress() const
	{
		return this->address;
	}
	int getCount() const
	{
		return count;
	}
	inline void printName(const string &p_name);
	void printAddress(const string &p_address);

	//static 成员函数可以定义在类的内部或者外部，在外部定义不需要重新加上static限定
	static void test111()
	{
		cout << "x = " << x << endl;//可以直接使用static成员
		cout << "y = " << y << endl;
	}

	static void testStatic();//声明static成员函数
	static void testConst(int a = x);//static只能使用static成员
	//static void testNoStatic(int = age);//不能使用非static成员做实际参数
protected:
private://private member
	string name;
	string address;
	int age;

	mutable int count;//const成员函数可以修改这种变量，不受const的限制，可以在成员函数中修改

	//static member
	static int x;//声明static数据成员，必须在外部定义，初始化
	//static int x = 30;不可以直接定义，初始化
	const static int y = 100;//初始化const static数据成员，必须在外部重新定义
};

int Person::x = 10;//定义static数据成员
//static int Person::x = 1;//定义static数据成员,但是不能再次加上限定static
const int Person::y;//const static必须在类外部定义，不需要再次指定初始值



void Person::testConst(int a)
{
	cout << "a = " << a << endl;
}

void Person::testStatic()
{
	//this->age;static函数没有this
	cout << "x = " << x << endl;//可以直接使用static成员
	cout << "y = " << y << endl;
}


void Person::testCount() const
{
	cout << "count: " << ++Person::count << endl;;
}


void Person::printName(const string &p_name)
{
	cout << p_name.c_str() << endl;
}

inline void Person::printAddress(const string &p_address)
{
	cout << p_address.c_str() << endl;
}

void Fun(const Person &p)
{
	cout << p.getName().c_str() << endl;
	cout << p.getAddress().c_str() << endl;
}



class people;//forward declaration

class Y;//必须加上Y的声明
class X
{
public:
	Y *y;
protected:
private:
};

class Y
{
public:
	X x;
protected:
private:
};



class MyClass//没有定义构造函数，并且所有的数据成员都是public，可以显式初始化
{

public:
	int a; 
	string str;	 
};






int main()
{ 
#if 0
	//能加static就加static，，，，记住
	
	//访问类的内部成员变量，内部函数的函数一般设计为普通成员函数
	//不访问类的内部成员，内部函数，需要设计静态函数

	
	//类的函数都是共享的，空指针也可以访问
	//类的函数作为代码，不计入sizeof的大小
	Person p;
	Person *p1 = new Person;
	p1 = nullptr;
	p1->test111();//访问正常
	//非静态要加上Person::*px
	void(Person::*px)(const string &) = &Person::printName;
	cout << typeid(&Person::printName).name() << endl;

	//静态不加Person::
	void(*pxx)() = &Person::test111;
	cout << typeid(&Person::test111).name() << endl;

#endif
	 



#if 0
	//变量的初始化细节
	int x = int(500);
	int a(5);
	int b(int(50));
	int c = 521;
	cout << a << " " << b << " " << x << endl;
#endif


#if 0
	Person p("chengzhi", "shenzhen");
	Person *p2 = &p;
	p.testStatic();
	p2->testStatic();
	p.testConst();
	p.test111();
#endif






#if 0	
	cout << p.getAddress().c_str() << " " << p.getName().c_str() << p.getCount() << endl;
	Person p2;//使用默认构造函数 
	Person p3 = Person();//使用默认构造函数
	cout << p2.getAddress().c_str() << " " << p2.getName().c_str() << p2.getCount() << endl;
// 	p.testCount();
// 	p.testCount();
// 	p.testCount();
// 	p.testCount();
// 	p.testCount();
	Person p4(20);

	MyClass m = { 1, "chengzhi" }; 
	//MyClass m3 = { "chengzhi", 1 };初始化的顺序与声明数据成员的顺序必须相同


	Fun(p);
	Person2 pp2;
#endif	

	system("pause");
	return 0;
}
