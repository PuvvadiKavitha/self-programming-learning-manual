#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class mystring
{
	//friend ostream& operator <<(ostream& os, const mystring& str);
	//friend istream& operator >>(istream& is, mystring& str);
public: 
	mystring() :p(nullptr), n(0){}
	~mystring()
	{
		delete[]p;
	}

	mystring(const char *str)
	{
		this->n = strlen(str) + 1;
		this->p = new char[this->n];
		strcpy(this->p, str);
	}
	
	mystring(const mystring &str)
	{
		//���
		this->n = str.n;
		this->p = new char[this->n];
 		strcpy(this->p, str.p);
		
		//ǳ����
// 		this->p = str.p;
// 		this->n = str.n;
	}

	mystring& operator =(const mystring& str)
	{
		this->n = str.n;
		this->p = new char[this->n];
		strcpy(this->p, str.p);
		return *this;
	}

	

	mystring operator+(const mystring &str)//����+
	{//����mystring����������캯����Ĭ����ǳ����
		int lenght = this->n + str.n - 1;
		mystring temp;//ʹ����ɺ�Ҳ�������������
		temp.n = lenght;
		temp.p = new char[temp.n];
		strcpy(temp.p, this->p);
		strcat(temp.p, str.p);
		return temp;//ǳ�����������Ϊ��������ֵ�и������ƣ��������غ��ڴ汻�ͷţ��������ַ���ָ��Ϊ����ָ��
		/*
		return temp;���2����
		1.����������mystring�ķ���ֵ�Ĳ���
		2.����temp�����������ͷ�temp���ڴ�
		*/
	}

	mystring add(const mystring &str)//ʹ�ó�Ա����
	{
		int lenght = this->n + str.n - 1;
		mystring temp;
		temp.n = lenght;
		temp.p = new char[temp.n];
		strcpy(temp.p, this->p);
		strcat(temp.p, str.p);
		return temp;
	}

	ostream& operator <<(ostream&)
	{
		cout << "Member Function" << endl;
		return cout << this->p << endl;
	}

	istream& operator >>(istream&)
	{
		cout << "Member Function" << endl;
		return cin >> this->p;
	}

protected:
public:
	char *p;
	int n;
};


ostream& operator <<(ostream& os, const mystring& str)
{
	cout << "Friend Function:" << endl;
	return cout << str.p << endl;
}


istream& operator >>(istream& is, mystring& str)
{
	cout << "Friend Function:" << endl;
	return cin >> str.p;
}

//����������Ԫ����Ԫ��Ϊ�˽������˽�б���������
//C++�������õĵط��ܾ�ָ��


int main789745()
{
	mystring str1("Hello");
	mystring str2("chengzhi");

	mystring str3;
	str3 = str1;
	//cout << str3.p << endl;
	cout << str3 << endl;
	cin >> str3;
	cout << str3 << endl;


#if 0
	cout << str1.p << str2.p << endl;

	mystring str3(str1);
	cout << str3.p << endl;

	mystring str4 = str1 + str2;
	cout << str4.p << endl;

	mystring str5 = str1.add(str2);
	cout << str5.p << endl;
#endif
	



	//cout << (str1 + str2).p << endl;



	system("pause");
	return 0;
}