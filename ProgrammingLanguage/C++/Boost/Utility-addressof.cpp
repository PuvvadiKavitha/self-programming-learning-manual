#include <iostream>
#include <boost/utility.hpp>


//������Ҫ���һ���������ʵ��ַʱ��ʹ�� addressof �����ع� operator& �����塣
using namespace std;
using namespace boost;

class my_class
{
public:
	int operator &() const
	{
		return 10;
	}
protected:
private:
};

int mainr757456()
{
	my_class s;
	//��ȡ�������ʵ��ַ����ʹ��������&��Ȼ��Ч
	cout << &s << endl;
	cout << boost::addressof(s) << endl;

	system("pause");
	return 0;
}