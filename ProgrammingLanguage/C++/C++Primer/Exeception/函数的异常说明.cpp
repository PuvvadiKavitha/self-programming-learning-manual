#include <iostream> 
#include <exception>
using namespace std;

class myclass
{
public:
	void show() throw();//�������׳��κ��쳣
	void show1() throw(underflow_error);//�׳�����ʱ�쳣
	void show3() const throw();
	//void show4() throw() const;constҪ��throwǰ��
	~myclass() throw()//����������Ӧ���׳��κ��쳣
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