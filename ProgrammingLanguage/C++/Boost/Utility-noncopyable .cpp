#include <iostream>
#include <boost/utility.hpp>

//boost::noncopyable �Ĺ���ԭ����ǽ�ֹ�������ĸ��ƹ��캯���͸�ֵ��������Ȼ��ʹ������Ϊ���ࡣ
//��һ�ַ����ǣ����ƹ��캯���͸�ֵ����������Ϊ˽�еĻ��Ǳ����Ĳ�����һ��ȱʡ���캯��(��Ϊ�����������Զ���������)��
using namespace std;
using namespace boost;

class please_no_copy : boost::noncopyable
{

};

/*
һ�����the big three��
���ƹ��캯����(����)�����������͸�ֵ���������е��κ�һ�����ֹ����壬
�ھ�������Ҫ������������֮ǰ����������ϸ�ؿ��������
���У�����㲻��Ҫ���ƣ��ǵ�ʹ�� boost::noncopyable ��

*/



/*
����������ʹ�� noncopyable ��

���͵ĸ��ƺ͸�ֵ����������

���ƺ͸�ֵ�Ľ�ֹӦ�þ���������



*/


int main6541321()
{
	//����ͨ�����롣����noncopyable�ĸ��ƹ��캯����˽�еģ���˶�d2���и��ƹ���ĳ��Ի�ʧ��
	please_no_copy p;
	//please_no_copy p2(p);
	//please_no_copy p3 = p;

	system("pause");
	return 0;
}