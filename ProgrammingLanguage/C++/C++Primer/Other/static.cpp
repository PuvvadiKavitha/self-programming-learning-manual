#include <iostream>

using namespace std;

class Test
{
public:
	static void test()
	{
		x = 0;
		y = 0;
	} 

public:
	static int x;//静态成员变量
	static int y;
};

//不对静态成员变量初始化，在编译的时候不会出错，如果在代码中也不使用这个成员变量，也不会出错，
//但是如果用类::静态成员变量调用就会出错，提示你必须对静态成员变量初始化
//int Test::x = 0;
//int Test::y = 0;

int main()
{
	Test::test();//调用使用了静态变量的函数就必须对使用的静态变量进行初始化。
	system("pause");
	return 0;
}