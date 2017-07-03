#include <iostream> 
using namespace std;
//这个demo要懂
class myclass
{
public:
	myclass()
	{
		cout << "myclass create" << endl;
	}
	~myclass()
	{
		cout << "myclass delete" << endl;
	}
};

template <typename T, int n>
class Auto_Point//智能指针
{
public:
	T* p;
	Auto_Point()
	{
		cout << "auto_point create" << endl;
		p = new T[n];
	}
	~Auto_Point()
	{
		cout << "auto_point delete" << endl;
	}

};

template <typename T>
class Free
{
public:
	Free()
	{
		cout << typeid(T).name()<< "Free create" << endl;
	}
	~Free()
	{
		cout << "Free delete" << endl;
	}
	T* operator ()(T* p)
	{
		delete []p;
		p = nullptr;
		return p;
	}

};

template <typename F, typename T>
T run(F f, T t)
{
	//1.调用f中()的重载析构t
	//2.会调用f的析构函数
	return f(t);
}


int mainqweqw()
{
	myclass m1;
	Auto_Point<decltype(m1), 3> a;
	Free<decltype(m1)> f;
	run(f, a.p);//类型一定要匹配
	m1.~myclass();
	system("pause");
	return 0;
}