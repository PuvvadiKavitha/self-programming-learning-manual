#include <iostream>
#include <typeinfo>
//rtti,ʵʱ���ͼ��
//typeid,  dynamic_cast�����������麯����
//ת����̬���ʹ��dynamic_castת��
//���Ͳ�ƥ��ת��ʧ�ܣ�����Ϊ��,��֤��ȫ

//�ܽ�
/*
static_cast:�����ת��
reinterpret_cast:ָ��֮���ת��
dynamic_cast:��̬֮���ת��
const_cast:ȡ��const���Ե�ת��
*/

/*typeid
ֻ�е�typeid�Ĳ������Ǵ����麯���������͵Ķ����ʱ��
���ܷ��ض�̬������Ϣ������ָ�뷵��ָ��ľ�̬�ģ�����ʱ����
typeid(p);����type_info�������
*/


//����ı�������
 
using namespace std;
class A
{
public:
	int num;
	static int data;
	virtual  void run()//�麯��--�麯����
	{
		std::cout << "Arun\n";
		
	}
};
int A::data = 1;



class B :public A
{
public:
	int num = 0;
	static int data;
	void run()
	{
		std::cout << "Brun\n";
	}
	void test()
	{
		std::cout << num << "\n";
		std::cout << "Btest\n";
	}
};
int B::data = 2;


void main231546()
{
	A a1;
	A* p1 = &a1;
	p1 = nullptr;
	try
	{
	     typeid(*p1);//p1 is nullptr
	}
	catch (bad_typeid e)//if p1 is nullptr and p1`s type is virtual then typeid(*p1) will throw "bad_typeid" exception
	{ 
		cout << "bad_typeid" << endl;
	} 
	
	
	std::cin.get();
}

void main4543()
{

	A a1;
	B b1;
	A *p1 = &a1;
	A *p2 = &b1;
	B *p3(nullptr);
	//p3 = static_cast<B *>(p1);//�����ת��-ֱ�Ӹ���ַ������ȫ�����麯���޹�,��û�ж��󶼿���
	p3 = reinterpret_cast<B*>(p2);//ָ��֮���ת��
	//p3 = static_cast<B *>(p2);
	
	std::cout << p3 << "\n";
	p3->test();
	 
	std::cin.get();
}

void main12313()
{

	A a1;
	B b1;
	A& p1 = a1;
	A& p2 = b1;
	B p3;
	B& pp3 = p3;
	try
	{
		p3 = dynamic_cast<B&>(p1);//����ת��ʧ�ܻ��׳�bad_cast�쳣�����쳣��typeinfoͷ�ļ��ж���
	}
	catch (bad_cast b)
	{
		cout << "bad cast" << endl;
	}
	  
 
	std::cin.get();
}

void main231asa3()
{

	A a1;
	B b1;
	A *p1 = &a1;
	A *p2 = &b1;
	B *p3(nullptr);
	p3 = dynamic_cast<B*>(p2);//��̬֮���ת��---��ȫ 
	//dynamic����Ҫ���麯�����Ǹ����麯����ת��������ת��
	//ת��ʧ��Ϊ��(������ص���������),ת���ɹ����ǵ�ַ
	//��Ŀ�ָ����Ե��ò��������ݵĺ���
	 
	std::cout << p3 << "\n";
	p3->test();


	/*�淶д��
	if (p3 = dynamic_cast<B*>(p2))
	{
	std::cout << p3 << "\n";
	p3->test();
	}*/
	 
	std::cin.get();
}
//ʵʱ���ͼ��RTTI

void mainasdas()
{
	
// 	A *p1 = new A;
// 	A *p2 = new B;
	A a1;
	B b1;
	A *p1 = &a1;
	A *p2 = &b1;
	//typeid���ܶ�̬��ȡ����
	//����A�����麯����ʱ������麯����typeid�Ϳ��Ի�ȡ����
	//�麯�������ȷ����������
	//A����û���麯�������������ǲ�ͬ�ġ�
	
	std::cout << typeid(p1).name() << "  " << typeid(p2).name() << std::endl;
	std::cout << (typeid(p1) == typeid(p2)) << "\n";

	std::cout << typeid(*p1).name() << "  " << typeid(*p2).name() << std::endl;
	std::cout << (typeid(*p1) == typeid(*p2)) << "\n";//���صķ�ʽ�ж������Ƿ�һ��



	std::cin.get();

}

void main22()
{
	B b1;
	b1.num = 10;//��Ա�����ĸ���, ��̬����Ҳ�Ḳ��
	b1.A::num = 20;
	std::cout << b1.num << "\n" << b1.A::num
		<< std::endl;
	std::cout << b1.data << "   " << b1.A::data << "\n";
	std::cout << &b1.data << "   " << &b1.A::data << "\n";

	std::cin.get();

}