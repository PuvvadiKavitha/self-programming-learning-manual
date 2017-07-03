#include <iostream> 
#include <exception>
using namespace std;

class myclass
{
public:
	void show() throw();//声明不抛出任何异常
	void show1() throw(underflow_error);//抛出运行时异常
	void show3() const throw();
	//void show4() throw() const;const要在throw前面
	~myclass() throw()//析构函数不应该抛出任何异常
	{

	}
	virtual void show5() throw()
	{}
protected:
private:
};

class myzhiclass : public myclass
{
public:
	void show5() throw(underflow_error)
	{

	}
protected:
private:
};



int main()
{
	//myclass* m = new myzhiclass;
	//m->show5();
	
	system("pause");
	return 0;
}