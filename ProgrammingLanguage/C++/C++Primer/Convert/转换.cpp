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

	//����ת������
	operator int()//��һ����Ķ���ת��Ϊint
	{
		//û�в��� û�з���ֵ ������return
		cout << "int" << endl;
		return (this->x + this->y) / 2;
	}

	operator double();//��������Ҫ�޶�����Ϊ����������ڲ�
protected:
public:
	int x;
	int y;
	
};

//��һ����Ķ���ת��Ϊdouble
area::operator double()//�ⲿ��Ҫ����޶�
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
		//����ֵ�и�������
		//area����ֻ�л����������Ϳ���ֱ�ӷ���-ǳ��������
		//������ָ��ȸ������Ͳ�����ֱ�ӷ���ֵ-�������
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
	//int a = m1;C��ʽ
	//int a = (int)m1;C��ʽ
	//int a = int(m1);//cpp��ʽ
	int a = static_cast<int>(m1);//cpp��ʽ
	cout << a << endl;
#endif
	




	//������������->������:���캯���͸�ֵ����
	//������->������������:����ת������


#if 0
	myclass m1(10);
	myclass m2(0);
	m2 = 5;//no operator = :use constructor
	//has operator = :use operator
	cout << m2.x << m2.y << endl;//cout�Զ����������0ȥ��

	double num = m2;//ʹ������ת������:������תΪ������������
	cout << num << endl;
#endif
	



	system("pause");
	return 0;
}