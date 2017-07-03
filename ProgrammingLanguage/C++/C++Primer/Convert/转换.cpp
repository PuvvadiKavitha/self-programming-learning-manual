#include <iostream> 
using namespace std;


class area
{
	//friend myclass::operator double();no
public:
	area()
	{

	}
	area(int num) :x(num), y(num)
	{
		//cout << "myclass" << num << endl;
	}

	void operator =(int num)
	{
		cout << "operator =" << num << endl;
		x = num;
		y = num;
	}

	//类型转换函数
	operator int()//把一个类的对象转换为int
	{
		//没有参数 没有返回值 必须有return
		cout << "int" << endl;
		return (this->x + this->y) / 2;
	}

	operator double();//声明不需要限定，因为声明在类的内部
protected:
public:
	int x;
	int y;
	
};

//把一个类的对象转换为double
area::operator double()//外部需要类的限定
{
	return (this->x + this->y) / 2.0 + 0.1;
}


class complex
{
public:
	int x;
	int y;
	//area->complex
	complex()
	{
	}
	complex(const area& ar)
	{
		cout << "complex constructor" << endl;
		this->x = ar.x;
		this->y = ar.y;
	}
	void operator =(const area& ar)
	{
		cout << "operator =" << endl;
		this->x = ar.x;
		this->y = ar.y;
	}

	//complex->area
	operator area()
	{
		cout << "type area" << endl;
		area temp;
		temp.x = this->x;
		temp.y = this->y;
		return temp;
		//返回值有副本机制
		//area类中只有基本数据类型可以直接返回-浅拷贝即可
		//否则含有指针等复合类型不可以直接返回值-必须深拷贝
	}
protected:
private:
};




int main()
{

	area ar(5);

	complex com0;
	com0 = ar;
	cout << com0.x << " " << com0.y << endl;

	complex com = ar; 
	cout << com.x << " " << com.y << endl;

	complex com1(ar); 
	cout << com1.x << " " << com1.y << endl;

	area ar2;
	ar2 = com;
	cout << ar2.x << " " << ar2.y << endl;



#if 0
	area m1(4);
	//int a = m1;C隐式
	//int a = (int)m1;C显式
	//int a = int(m1);//cpp显式
	int a = static_cast<int>(m1);//cpp显式
	cout << a << endl;
#endif
	




	//基本数据类型->类类型:构造函数和赋值重载
	//类类型->基本数据类型:类型转换函数


#if 0
	myclass m1(10);
	myclass m2(0);
	m2 = 5;//no operator = :use constructor
	//has operator = :use operator
	cout << m2.x << m2.y << endl;//cout自动把无意义的0去掉

	double num = m2;//使用类型转换函数:类类型转为基本数据类型
	cout << num << endl;
#endif
	



	system("pause");
	return 0;
}