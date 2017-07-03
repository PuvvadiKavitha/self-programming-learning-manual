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
		//深拷贝
		this->n = str.n;
		this->p = new char[this->n];
 		strcpy(this->p, str.p);
		
		//浅拷贝
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

	

	mystring operator+(const mystring &str)//重载+
	{//返回mystring调用深拷贝构造函数，默认是浅拷贝
		int lenght = this->n + str.n - 1;
		mystring temp;//使用完成后也会调用析构函数
		temp.n = lenght;
		temp.p = new char[temp.n];
		strcpy(temp.p, this->p);
		strcat(temp.p, str.p);
		return temp;//浅拷贝情况，因为函数返回值有副本机制，函数返回后，内存被释放，拷贝的字符串指针为悬垂指针
		/*
		return temp;完成2件事
		1.调用深拷贝完成mystring的返回值的操作
		2.调用temp的析构函数释放temp的内存
		*/
	}

	mystring add(const mystring &str)//使用成员函数
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

//尽量别用友元，友元是为了解决访问私有变量的问题
//C++能用引用的地方拒绝指针


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