#include <iostream>
#include <algorithm>
#include <numeric> 
#include <iterator>
using namespace std;

class A
{
public:
	A(int num) :i(num)
	{

	}
	operator int() const//类型转换函数
	{
		return i;
	}
protected:
private:
	int i;
};

int main2131212312()
{
	//vector和list底层都使用这种迭代器
	//作用：重写vector的时候会用到，不经常用
	allocator<A> mya;//分配迭代器
	A* p = mya.allocate(10);
	A* px = p;
	raw_storage_iterator<A*, A> rsi(p);//存储迭代器

	for (int i = 0; i < 10; i++)
	{
		*rsi++ = A(i);//通过迭代器访问,利用类型转换函数将类类型转换为int类型 
	}

	for (int i = 0; i < 10; i++)
	{
		cout << static_cast<int>(*p++) << endl;
	} 
	
	mya.deallocate(px, 10);//如果释放内存,必须保留原来的内存地址，必须释放最原始的位置


	system("pause");
	return 0;
}
















