#include <iostream>

using namespace std;

class Test
{
public:
	static void test()
	{
		x = 0;
		y = 0;
	} 

public:
	static int x;//��̬��Ա����
	static int y;
};

//���Ծ�̬��Ա������ʼ�����ڱ����ʱ�򲻻��������ڴ�����Ҳ��ʹ�������Ա������Ҳ�������
//�����������::��̬��Ա�������þͻ������ʾ�����Ծ�̬��Ա������ʼ��
//int Test::x = 0;
//int Test::y = 0;

int main()
{
	Test::test();//����ʹ���˾�̬�����ĺ����ͱ����ʹ�õľ�̬�������г�ʼ����
	system("pause");
	return 0;
}