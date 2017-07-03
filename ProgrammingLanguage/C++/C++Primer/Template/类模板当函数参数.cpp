#include <iostream>
#include <array>
using namespace std;

template<typename T, int n>
void fun(array<T, n> ar)//有类模板参数的函数，一定是函数模板
{
	for (auto &i : ar)
	{
		i += 1;
		
	}
	for (auto i : ar)
	{
		cout << i << endl;
	}

}



int main12312()
{
	array<int, 5> ar = {1, 2, 3, 4, 5};
	fun<int, 5>(ar);//代码规范必须加上类型，个数，
	//函数模板会根据参数自动推理，
	system("pause");
	return 0;
}
