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

	//��ͨ����������Ĺ����������һ�����������ڶ�����ָʾ��ʼ����λ�õĵ����� 
	insert_iterator< deque<int> > i_it(d, d.end());
	//�����begin, ��һֱ�ڿ�ʼ��beginλ�ò��룬��������front_insert_iterator����һֱ��ͷ������
	//�����end����һֱ��β������
	*i_it = 44;
	*i_it = 55;
	*i_it = 66;
	cout << endl;
	copy(d.begin(), d.end(), ostream_iterator<int>(cout, " "));







	system("pause");
	return 0;
}