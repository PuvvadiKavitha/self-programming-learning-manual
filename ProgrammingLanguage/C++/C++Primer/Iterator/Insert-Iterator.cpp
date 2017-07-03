#include <iostream>
#include <algorithm>
#include <numeric> 
#include <iterator>
#include <deque>


using namespace std;
int main234456456()
{
	deque<int> d;
	d.push_back(11); 
	d.push_back(22);

	front_insert_iterator< deque<int> > f_it(d);
	*f_it = 11; 
	*f_it = 22; 
	copy(d.begin(), d.end(), ostream_iterator<int>(cout, " "));

	back_insert_iterator< deque<int> > b_it(d);
	*b_it = 33;
	cout << endl;
	copy(d.begin(), d.end(), ostream_iterator<int>(cout, " "));

	//普通插入迭代器的构造参数，第一个是容器，第二个是指示起始插入位置的迭代器 
	insert_iterator< deque<int> > i_it(d, d.end());
	//如果是begin, 则一直在开始的begin位置插入，而不是像front_insert_iterator那样一直在头部插入
	//如果是end，就一直在尾部插入
	*i_it = 44;
	*i_it = 55;
	*i_it = 66;
	cout << endl;
	copy(d.begin(), d.end(), ostream_iterator<int>(cout, " "));







	system("pause");
	return 0;
}