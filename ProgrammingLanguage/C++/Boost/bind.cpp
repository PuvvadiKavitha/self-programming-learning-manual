#include <iostream>
#include <boost/bind.hpp>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;


class add : public binary_function<int, int, void>
{
public:
	void operator ()(int x, int y)const
	{
		cout << x + y << " ";
	}
protected:
private:
};


void addx(int x, int y)
{
	cout << x + y << " ";
}

int main231rtr()
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	//Bind1st need the class add:
	//1.To inherit binary_function<int, int, void>
	//2.Need the function : type cast function
	cout << "No use the boost bind:" << endl;
	for_each(vec.begin(), vec.end(), bind1st(add(), 10));//functor

	cout << endl << "Use the boost bind:" << endl;
	//Bind parament to function
	//Need boost lib
	//bind设置默认参数调用，函数副本机制，不能拷贝构造
	for_each(vec.begin(), vec.end(), bind(addx, 10, _1));

	cout << endl;

	system("pause");
	return 0;
}