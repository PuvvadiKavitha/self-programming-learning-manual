#include <iostream> 
#include <cstdlib>
using namespace std;

template <typename T>
class myclassA
{
public:
	virtual void print() = 0;
	T x;
	T y;
};


template <typename T>
class myclassB
{
public:
	virtual void run() = 0;
	T z;
	char *cmd;
};

template <typename T>
class myclassAB : public myclassA<T>, public myclassB<T>//��̳�
{
	void print()
	{
		cout << x << " " << y << endl;
	}
	void run()
	{
		cout << z << endl;
		system(cmd);
	}
};
 

template <typename T>
class myclassAZhi : public myclassA<T>
{
public:
	void print()
	{
		cout << x << " " << y << endl;
	}

};



int main()
{
	myclassA<int>* paa = new myclassAZhi<int>;
	paa->x = 1;
	paa->y = 2;
	paa->print();


	//���ؼ̳�
	//����ֻ�ܷ����Լ����麯�����ߴ洢����
	//��Ҫ�������ָ��

	myclassAB<int> AB;
	AB.x = 1;
	AB.y = 2;
	AB.z = 3;
	AB.cmd = "calc";

	myclassA<int>* pa = &AB;
	pa->print();

	myclassB<int>* pb = &AB;
	pb->run(); 


	system("pause");
	return 0;
}