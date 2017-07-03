#include<iostream>
#include <stdio.h>
#include<stdlib.h>
using namespace std;


void *operator new(size_t size)//对全局new的重载
{
	if (0 == size)
	{
		return 0;
	}
	void *p = malloc(sizeof(size));
	std::cout << "全局new被调用，内存被分配" << p << std::endl;
	return p;
}

void operator delete(void *p)//对全局delete的重载
{
	std::cout << "全局delete被调用，内存被回收" << p << std::endl;

	free(p);
}

void *operator new[](size_t size)
{

	std::cout << "全局数组new被调用，内存即将被分配" << std::endl;
	return operator new(size);

}

void operator delete[](void *p)
{
	std::cout << "全局数组delete被调用，内存即将被回收" << std::endl;
	return operator delete(p);
}




class chengzhi
{
public:
	chengzhi()
	{
		std::cout << "chengzhi被创建" << std::endl;
	}
	~chengzhi()
	{
		std::cout << "chengzhi被销毁" << std::endl;
	}

	static void* operator new(size_t size)
	{
		jishuqi++;
		std::cout << "局部new被调用，对象被创建" << std::endl;
		chengzhi* p = ::new chengzhi;
		return p;
	}

	static void operator delete(void *p)
	{
		jishuqi--;
		std::cout << "局部delete被调用，对象被销毁" << std::endl;
		::delete p;
	}

	static void *operator new[](size_t size)
	{
		std::cout << "对象数组被创建" << std::endl; 
		return operator new(size);
	}

	static void operator delete[](void *p)
	{
		std::cout << "对象数组被销毁" << std::endl;
		return operator delete(p); 
	}
	static int jishuqi;
};

int chengzhi::jishuqi = 0;



void main()
{
	 
	chengzhi* p = new chengzhi;
	delete p;


// 	chengzhi *p = new chengzhi[3];
// 	delete[]p;


	system("pause");
}