#include<iostream>
#include <stdio.h>
#include<stdlib.h>
using namespace std;


void *operator new(size_t size)//��ȫ��new������
{
	if (0 == size)
	{
		return 0;
	}
	void *p = malloc(sizeof(size));
	std::cout << "ȫ��new�����ã��ڴ汻����" << p << std::endl;
	return p;
}

void operator delete(void *p)//��ȫ��delete������
{
	std::cout << "ȫ��delete�����ã��ڴ汻����" << p << std::endl;

	free(p);
}

void *operator new[](size_t size)
{

	std::cout << "ȫ������new�����ã��ڴ漴��������" << std::endl;
	return operator new(size);

}

void operator delete[](void *p)
{
	std::cout << "ȫ������delete�����ã��ڴ漴��������" << std::endl;
	return operator delete(p);
}




class chengzhi
{
public:
	chengzhi()
	{
		std::cout << "chengzhi������" << std::endl;
	}
	~chengzhi()
	{
		std::cout << "chengzhi������" << std::endl;
	}

	static void* operator new(size_t size)
	{
		jishuqi++;
		std::cout << "�ֲ�new�����ã����󱻴���" << std::endl;
		chengzhi* p = ::new chengzhi;
		return p;
	}

	static void operator delete(void *p)
	{
		jishuqi--;
		std::cout << "�ֲ�delete�����ã���������" << std::endl;
		::delete p;
	}

	static void *operator new[](size_t size)
	{
		std::cout << "�������鱻����" << std::endl; 
		return operator new(size);
	}

	static void operator delete[](void *p)
	{
		std::cout << "�������鱻����" << std::endl;
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