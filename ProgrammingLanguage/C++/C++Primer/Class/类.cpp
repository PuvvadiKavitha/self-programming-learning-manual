#include <iostream>

using namespace std;


class Person2
{
public:
	void test()
	{
		cout << "Person2" << endl;
	}
protected:
private:
};


class Person111;//class declaration

//class;class keyword
class Person
{//class scope��������
public://access label
	friend class Person2;//���Է������е��κεط�
	friend void Person2::test();
	friend void Fun(const Person &p);



	Person(const string &p_name, const string &p_address)
		: name(p_name), address(p_address), count(0)//constructor initializer list
	{}
	Person(){}//Always have the default constructor
	explicit Person(const int &p_age)//explicit constructor//��ʽ
	{
		age = p_age;
	}
	void testCount() const;
	string getName() const//const member function
	{
		return this->name;
	}
	string getAddress() const
	{
		return this->address;
	}
	int getCount() const
	{
		return count;
	}
	inline void printName(const string &p_name);
	void printAddress(const string &p_address);

	//static ��Ա�������Զ���������ڲ������ⲿ�����ⲿ���岻��Ҫ���¼���static�޶�
	static void test111()
	{
		cout << "x = " << x << endl;//����ֱ��ʹ��static��Ա
		cout << "y = " << y << endl;
	}

	static void testStatic();//����static��Ա����
	static void testConst(int a = x);//staticֻ��ʹ��static��Ա
	//static void testNoStatic(int = age);//����ʹ�÷�static��Ա��ʵ�ʲ���
protected:
private://private member
	string name;
	string address;
	int age;

	mutable int count;//const��Ա���������޸����ֱ���������const�����ƣ������ڳ�Ա�������޸�

	//static member
	static int x;//����static���ݳ�Ա���������ⲿ���壬��ʼ��
	//static int x = 30;������ֱ�Ӷ��壬��ʼ��
	const static int y = 100;//��ʼ��const static���ݳ�Ա���������ⲿ���¶���
};

int Person::x = 10;//����static���ݳ�Ա
//static int Person::x = 1;//����static���ݳ�Ա,���ǲ����ٴμ����޶�static
const int Person::y;//const static���������ⲿ���壬����Ҫ�ٴ�ָ����ʼֵ



void Person::testConst(int a)
{
	cout << "a = " << a << endl;
}

void Person::testStatic()
{
	//this->age;static����û��this
	cout << "x = " << x << endl;//����ֱ��ʹ��static��Ա
	cout << "y = " << y << endl;
}


void Person::testCount() const
{
	cout << "count: " << ++Person::count << endl;;
}


void Person::printName(const string &p_name)
{
	cout << p_name.c_str() << endl;
}

inline void Person::printAddress(const string &p_address)
{
	cout << p_address.c_str() << endl;
}

void Fun(const Person &p)
{
	cout << p.getName().c_str() << endl;
	cout << p.getAddress().c_str() << endl;
}



class people;//forward declaration

class Y;//�������Y������
class X
{
public:
	Y *y;
protected:
private:
};

class Y
{
public:
	X x;
protected:
private:
};



class MyClass//û�ж��幹�캯�����������е����ݳ�Ա����public��������ʽ��ʼ��
{

public:
	int a; 
	string str;	 
};






int main()
{ 
#if 0
	//�ܼ�static�ͼ�static����������ס
	
	//��������ڲ���Ա�������ڲ������ĺ���һ�����Ϊ��ͨ��Ա����
	//����������ڲ���Ա���ڲ���������Ҫ��ƾ�̬����

	
	//��ĺ������ǹ���ģ���ָ��Ҳ���Է���
	//��ĺ�����Ϊ���룬������sizeof�Ĵ�С
	Person p;
	Person *p1 = new Person;
	p1 = nullptr;
	p1->test111();//��������
	//�Ǿ�̬Ҫ����Person::*px
	void(Person::*px)(const string &) = &Person::printName;
	cout << typeid(&Person::printName).name() << endl;

	//��̬����Person::
	void(*pxx)() = &Person::test111;
	cout << typeid(&Person::test111).name() << endl;

#endif
	 



#if 0
	//�����ĳ�ʼ��ϸ��
	int x = int(500);
	int a(5);
	int b(int(50));
	int c = 521;
	cout << a << " " << b << " " << x << endl;
#endif


#if 0
	Person p("chengzhi", "shenzhen");
	Person *p2 = &p;
	p.testStatic();
	p2->testStatic();
	p.testConst();
	p.test111();
#endif






#if 0	
	cout << p.getAddress().c_str() << " " << p.getName().c_str() << p.getCount() << endl;
	Person p2;//ʹ��Ĭ�Ϲ��캯�� 
	Person p3 = Person();//ʹ��Ĭ�Ϲ��캯��
	cout << p2.getAddress().c_str() << " " << p2.getName().c_str() << p2.getCount() << endl;
// 	p.testCount();
// 	p.testCount();
// 	p.testCount();
// 	p.testCount();
// 	p.testCount();
	Person p4(20);

	MyClass m = { 1, "chengzhi" }; 
	//MyClass m3 = { "chengzhi", 1 };��ʼ����˳�����������ݳ�Ա��˳�������ͬ


	Fun(p);
	Person2 pp2;
#endif	

	system("pause");
	return 0;
}
