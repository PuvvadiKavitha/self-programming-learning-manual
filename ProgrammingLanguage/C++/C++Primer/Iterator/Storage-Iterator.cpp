#include <iostream>
#include <algorithm>
#include <numeric> 
#include <iterator>
using namespace std;

class A
{
public:
	A(int num) :i(num)
	{

	}
	operator int() const//����ת������
	{
		return i;
	}
protected:
private:
	int i;
};

int main2131212312()
{
	//vector��list�ײ㶼ʹ�����ֵ�����
	//���ã���дvector��ʱ����õ�����������
	allocator<A> mya;//���������
	A* p = mya.allocate(10);
	A* px = p;
	raw_storage_iterator<A*, A> rsi(p);//�洢������

	for (int i = 0; i < 10; i++)
	{
		*rsi++ = A(i);//ͨ������������,��������ת��������������ת��Ϊint���� 
	}

	for (int i = 0; i < 10; i++)
	{
		cout << static_cast<int>(*p++) << endl;
	} 
	
	mya.deallocate(px, 10);//����ͷ��ڴ�,���뱣��ԭ�����ڴ��ַ�������ͷ���ԭʼ��λ��


	system("pause");
	return 0;
}
















