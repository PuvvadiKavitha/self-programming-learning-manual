#include <iostream> 
using namespace std;
//���demoҪ��
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
class Auto_Point//����ָ��
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
	//1.����f��()����������t
	//2.�����f����������
	return f(t);
}


int mainqweqw()
{
	myclass m1;
	Auto_Point<decltype(m1), 3> a;
	Free<decltype(m1)> f;
	run(f, a.p);//����һ��Ҫƥ��
	m1.~myclass();
	system("pause");
	return 0;
}