#include <iostream>

using namespace std;


//����ָ��ı�����һ����ģ��
template <class T>
class AutoPoint
{
public:
	AutoPoint():ptr(nullptr){}

	AutoPoint(T *p) :ptr(p){}

	~AutoPoint()
	{
		if (ptr != nullptr)
		{
			delete ptr;
		}
	}
	T& operator *()
	{
		return *ptr;
	}
	T* operator ->()
	{
		return ptr;
	}
private:
	T *ptr;
};


class test
{
public:
	test()
	{
		cout << "test create" << endl;
	}
	~test()
	{
		cout << "test destory" << endl;
	}
	void print()
	{
		cout << "test print" << endl;
	}
protected:
private:
};

void fun()
{
	
	AutoPoint<test> my_ptr(new test);
	my_ptr->print();
	(*my_ptr).print();
}
int mainwer()
{
	fun();//�Զ��ͷ�ָ���ڴ�


	system("pause");
	return 0;
}
