#include <iostream> 

namespace myspace
{
//private:�����ռ�ͽṹ��һ��ȫ͸��
	int a(5);
	void print()
	{
		std::cout << "myspace" << std::endl;
	}

	namespace myzhispace//�����ռ����Ƕ��
	{
		int a(555555);
	}

}
namespace myspace//��myspace����չ
{
	//int a(2323);��չ��ʱ�����ض���
	int y(444);
}


namespace mymymyspace = myspace;//�������ռ��������


//using namespace youspace;//using�����������ռ�ĺ���
namespace youspace
{
	int a(15);
	void print()
	{
		std::cout << "youspace" << std::endl;
	}
}

// namespace//�൱��û�������ռ�
// {
// 	int a(555);
// 	void print()
// 	{
// 		std::cout << "no name" << std::endl;
// 	}
// }


/*
void go()
{
	//�����ռ�����ڿ�������ݣ��������Ƕ��忪ʼ����������
	using namespace youspace;
	std::cout << a << std::endl;
}
*/

using namespace myspace;//������Ϊ�Ӵ��뿪ʼ������
int main()
{ 
	//go();
	int b(55);//�ֲ��ı�������û�����Ƶ������ռ��еı���
	std::cout << "main b = " << b << std::endl;
	std::cout << "main a = " << myspace::a << std::endl;
	std::cout << "myspace y = " <<myspace::y << std::endl;
	std::cout << "mymymyspace y = " << mymymyspace::y << std::endl;
	std::cout << "myzhispace y = " << myspace::myzhispace::a << std::endl;
	std::cout << "youspace a = " << youspace::a << std::endl;

	//print();//�ֲ��Ҳ�������û�����Ƶ������ռ�
	myspace::print();
	youspace::print();
	std::cout << "myspace print = " << myspace::print << std::endl;
	std::cout << "youspace print = " << youspace::print << std::endl;
	system("pause");
	return 0;
}



