#include <iostream>
#include <algorithm>
#include <numeric> 
#include <iterator>
#include <vector>

using namespace std;
int main()
{
	vector<int> myvec;
	myvec.push_back(1);
	myvec.push_back(2);
	myvec.push_back(3);
	myvec.push_back(4);
	myvec.push_back(5);

	//迭代器指向的位置不能改变, 只能指向一个位置
	//指向的位置的元素的值可以改变
	const vector<int>::iterator it = myvec.begin();
	*it = 1111;
	//it = myvec.end();

	//迭代器指向的位置可以改变但是指向的位置的值不能改变
	//即该迭代器是只读迭代器
	vector<int>::const_iterator c_it = myvec.begin();
	c_it = myvec.end();
	//*c_it = 11;



	system("pause");
	return 0;
}
