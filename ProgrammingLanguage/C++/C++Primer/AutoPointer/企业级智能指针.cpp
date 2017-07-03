#include <iostream>
#include <boost/scoped_ptr.hpp>
#include <boost/scoped_array.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/shared_array.hpp>
#include <boost/weak_ptr.hpp>

//ѧ��boost�������

using namespace std;
using namespace boost;

int main()
{
	boost::shared_ptr<int> p(new int(100));
	boost::weak_ptr<int> pw(p);//��ָ�볣�����۲칲��ָ�룬�����ڶ��߳�
	boost::shared_ptr<int> px = pw.lock();//�����ڴ治���ͷţ�������������ֵ�����޸� 
	//p.reset();//��ָ������Ϊ�գ�ָ����ڴ汻�ͷ�, ��������ָ��󴥷��������������쳣
	*p = 200;
	cout << *p << endl;

	  

	cin.get();
	return 0;
}
 

int maindfs()
{
	//5000 ~ 10000�д���
	boost::shared_ptr<int> p(new int);
	boost::shared_ptr<int> px(p);//��������ָ�����ʵ�ֹ���һƬ�ڴ�

	boost::shared_array<int> p2(new int[5]);
	boost::shared_array<int> p3(p2);//����ʹ�ÿ�����ʼ��

	cin.get();
	return 0;
} 


int mainafdas()
{
	boost::scoped_array<int> p(new int[5]);//���ܹ��������ָ��
	p[0] = 1;
	p[1] = 2;
	cout << *p.get() << endl; 
	 
	cin.get();
	return 0;
}





int mainsdfa()
{
	boost::scoped_ptr<int> p(new int);//�Զ��ͷ��ڴ�
	*p = 10;
	cout << &p << endl; //ָ���Լ��ĵ�ַ
	cout << p.get() << endl;//�õ�ָ�봢��ĵ�ַ
	cout << *p.get() << endl;//�õ�ָ��ָ���ֵ
	cout << *p << endl;

	p.reset(new int);//����ָ��
	*p = 3;
	cout << p.get() << endl;
	cout << *p.get() << endl;

	int *px = new int(5);
	//p = px;����ָ�����ָͨ��֮�䲻����ֱ�Ӹ�ֵ
	 
	system("pause");
	return 0;
}
