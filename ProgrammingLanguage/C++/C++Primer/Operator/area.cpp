#include <iostream> 
using namespace std;


class area
{
public:
	double x;
	double y;
	area() :x(0), y(0){}
	~area(){}
	area(double x, double y) :x(x), y(y){}
	
	/*Ϊ�����������Ͳ���������һ�£��Ӽ��˳�������ֵ����������*/
	area operator +(const area& ar)
	{
		area temp;
		temp.x = this->x + ar.x;
		temp.y = this->y + ar.y;
		return temp;  
	}

	area operator -(const area& ar)
	{
		area temp;
		temp.x = this->x - ar.x;
		temp.y = this->y - ar.y;
		return temp;
	}
	area operator *(const area& ar)
	{
		area temp;
		temp.x = this->x * ar.x;
		temp.y = this->y * ar.y;
		return temp;
	}
	area operator /(const area& ar)
	{
		area temp;
		temp.x = this->x / ar.x;
		temp.y = this->y / ar.y;
		return temp;
	}
	//һ�����ظ�ֵ�͸��ϸ�ֵ��������Ҫ�����������������
	area& operator +=(const area& ar)
	{
		this->x = this->x + ar.x;
		this->y = this->y + ar.y;
		return (*this);
	}
// 	area& operator +=(area& a1, const area& a2)
// 	{
// 		a1 = a1 + a2;
// 		return a1;
// 	}

	area& operator -=(const area& ar)
	{
		this->x = this->x - ar.x;
		this->y = this->y - ar.y;
		return (*this);
	}
	area& operator *=(const area& ar)
	{
		this->x = this->x * ar.x;
		this->y = this->y * ar.y;
		return (*this);
	}
	area& operator /=(const area& ar)
	{
		this->x = this->x / ar.x;
		this->y = this->y / ar.y;
		return (*this);
	}
	area& operator =(const area& ar)
	{
		cout << "op =" << endl;
		this->x = ar.x;
		this->y = ar.y;
		return (*this);
	}
protected:
private:
};

int mainete()
{
	area a(5.0, 5.0);
	area b(6.0, 6.0);
	area c = a + b;
	area d = a - b;
	area e = a * b;
	area f = a / b; 
	cout << a.x << " " << a.y << endl;
	cout << b.x << " " << b.y << endl;
	cout << c.x << " " << c.y << endl;
	cout << d.x << " " << d.y << endl;
	cout << e.x << " " << e.y << endl;
	cout << f.x << " " << f.y << endl;


	a += b;
	cout << a.x << " " << a.y << endl;

	c -= d;
	cout << c.x << " " << c.y << endl;

	d *= e;
	cout << d.x << " " << d.y << endl;

	e /= f;
	cout << e.x << " " << e.y << endl;

	e = f;
	cout << e.x << " " << e.y << endl;
	system("pause");
	return 0;
}