#include <iostream>
 
//全局变量声明
extern int a;



int main()
{ 
	//定义只能有一个
	int a = static_cast<int>(3.12);
	int b = (int)3.22;

	//赋值
	a = 1; 
	system("pause");
	return 0;
} 

int test()
{
	return 0;
}
 
 