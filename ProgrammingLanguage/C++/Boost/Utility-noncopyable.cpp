#include <iostream>
#include <boost/utility.hpp>

/*
	boost::noncopyable �Ĺ���ԭ����ǽ�ֹ�������ĸ��ƹ��캯���͸�ֵ��������Ȼ��ʹ������Ϊ���ࡣ
	��һ�ַ����ǣ����ƹ��캯���͸�ֵ����������Ϊ˽�еĻ��Ǳ����Ĳ�����һ��ȱʡ���캯��(��Ϊ�����������Զ���������)��
 */
class please_no_copy : boost::noncopyable
{

};


/*
	����������ʹ�� noncopyable :
	1. ���͵ĸ��ƺ͸�ֵ����������
	2. ���ƺ͸�ֵ�Ľ�ֹӦ�þ���������
*/
int main() {
	// p don't allow copy to other!
	please_no_copy p;
	//please_no_copy p2(p);
	//please_no_copy p3 = p;

	return 0;
}
