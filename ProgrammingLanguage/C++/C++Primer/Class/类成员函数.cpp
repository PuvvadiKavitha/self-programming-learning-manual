#include<iostream>

using namespace std;

//����᣺���Ա����ָ�룬���Ա��������ָ�룬���Ա����ָ������


//��ҵ��ʹ�����Ա����ָ��
//0-100
//���������ң��ƶ����Ŵ���С

class op
{
public:
	op(int x, int y) :a(x), b(y)
	{

	}
	int add(int a, int b)
	{
		return a + b;
	}
	int mul(int a, int b)
	{
		return a * b;
	}
	int divv(int a, int b)
	{
		return a / b;
	}
	int sub(int a, int b)
	{
		return a - b;
	}
private:
	int a;
	int b;
};




void main121212()
{
	op op1(100, 10);
	auto fun1 = &op::add;//fun1�޷�����
	cout << typeid(fun1).name() << endl;//��ӡadd������
	int(op::*p)(int, int) = &op::add;//�������Ա����ָ�룬ָ������������
	cout << (op1.*p)(40, 50) << endl;//���÷�ʽ,���Ա��������thisָ�룬Ҳ���Ƕ����ַ
	//���Ա����ָ�����ͨ������������� 
	cin.get();

}


void main()
{

	op op1(100, 10);

	//���Ա����ָ������p   p��һ������ָ��
	int(op::*p[4])(int a, int b) = { &op::add, &op::sub, &op::mul, &op::divv};

	//�±����
	for (int i = 0; i < 4;i++)
	{ 
		cout << (op1.*p[i])(500, 50) << endl; //p[i]��һ�����Ա����ָ��
	}
	 
	//����һ��ָ��������Ҫһ������ָ��
	//int(op::**pp)(int a, int b)�������Ա����ָ��
	
	for (int(op::**pp)(int a, int b) = p; pp < p + 4; pp++)
	{ 
		cout <<  (op1.**pp)(500, 50) << endl;//**pp�����Ա����ָ��
	}

	cin.get();
}