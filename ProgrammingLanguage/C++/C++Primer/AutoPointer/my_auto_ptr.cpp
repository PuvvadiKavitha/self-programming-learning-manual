#include <iostream>
using namespace std;


class U_ptr
{ 
private:
	friend class MyAutoPtr;
	int *ip;
	size_t use;
	U_ptr(int *p) :ip(p), use(1){}
	~U_ptr(){ delete ip; }
};


class MyAutoPtr
{
public: 
	MyAutoPtr(){}
	MyAutoPtr(int *p, int i) : ptr(new U_ptr(p)), val(i)
	{
		cout << "MyAutoPtr():ptr use:" << ptr->use << endl;
	}
	MyAutoPtr(const MyAutoPtr &orig) : ptr(orig.ptr), val(orig.val)
	{ 
		ptr->use++;
		cout << "copy-MyAutoPtr():ptr use:" << ptr->use << endl;
	}
	MyAutoPtr &operator=(const MyAutoPtr &rhs);
	~MyAutoPtr()
	{
		if (--ptr->use == 0)
		{
			cout << "~MyAutoPtr():ptr use:" << ptr->use << endl;
			delete ptr;
		}
		cout << "~MyAutoPtr():ptr use:" << ptr->use << endl;
	} 
private:
	U_ptr *ptr;
	int val;
};

MyAutoPtr &MyAutoPtr::operator=(const MyAutoPtr &rhs)
{
	rhs.ptr->use++;
	cout << "operator=:rhs use:" << rhs.ptr->use << endl;
	//cout << "operator=:ptr use:" << ptr->use << endl;
	if (--ptr->use == 0)
	{
		cout << "operator=:ptr use:" << ptr->use << endl;
		delete ptr;
	}
	ptr = rhs.ptr;
	val = rhs.val;
	return *this;
}
  

int main()
{
	int a = 100;
	int b = 10;
	int *px = &a;
	int *pb = &b;
	int i = 200;
	MyAutoPtr ptr(px, i);
	MyAutoPtr ptr2(ptr); 
	MyAutoPtr ptr3 = ptr;
	ptr.~MyAutoPtr();
	ptr2.~MyAutoPtr(); 
	system("pause");
	return 0;
}
