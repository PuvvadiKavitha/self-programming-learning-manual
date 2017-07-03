#include <iostream> 

namespace myspace
{
//private:命名空间和结构体一样全透明
	int a(5);
	void print()
	{
		std::cout << "myspace" << std::endl;
	}

	namespace myzhispace//命名空间可以嵌套
	{
		int a(555555);
	}

}
namespace myspace//对myspace的拓展
{
	//int a(2323);拓展的时候不能重定义
	int y(444);
}


namespace mymymyspace = myspace;//给命名空间起个别名


//using namespace youspace;//using必须在命名空间的后面
namespace youspace
{
	int a(15);
	void print()
	{
		std::cout << "youspace" << std::endl;
	}
}

// namespace//相当于没有命名空间
// {
// 	int a(555);
// 	void print()
// 	{
// 		std::cout << "no name" << std::endl;
// 	}
// }


/*
void go()
{
	//命名空间如果在块语句内容，作用域是定义开始到块语句结束
	using namespace youspace;
	std::cout << a << std::endl;
}
*/

using namespace myspace;//作用域为从代码开始到结束
int main()
{ 
	//go();
	int b(55);//局部的变量屏蔽没有名称的命名空间中的变量
	std::cout << "main b = " << b << std::endl;
	std::cout << "main a = " << myspace::a << std::endl;
	std::cout << "myspace y = " <<myspace::y << std::endl;
	std::cout << "mymymyspace y = " << mymymyspace::y << std::endl;
	std::cout << "myzhispace y = " << myspace::myzhispace::a << std::endl;
	std::cout << "youspace a = " << youspace::a << std::endl;

	//print();//局部找不到就找没有名称的命名空间
	myspace::print();
	youspace::print();
	std::cout << "myspace print = " << myspace::print << std::endl;
	std::cout << "youspace print = " << youspace::print << std::endl;
	system("pause");
	return 0;
}



