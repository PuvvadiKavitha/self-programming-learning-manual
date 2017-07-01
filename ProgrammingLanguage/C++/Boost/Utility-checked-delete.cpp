#include <iostream>
#include <boost/checked_delete.hpp>
using namespace std;
using namespace boost;

//checked_delete��ʵ��
template <typename T>
inline void my_checked_delete(T* t)
{
	/*
	������뷨�Ǵ���һ��char�����飬�����Ԫ������ΪT�Ĵ�С��
	��� checked_delete ��һ�������������� T ��ʵ���������뽫��ʧ�ܣ�
	��Ϊ sizeof(T) �᷵�� 0, ������һ��0��Ԫ�ص�(�Զ�)�����ǷǷ��ġ�
	*/
	typedef char type_must_be_complete[sizeof(T)];

	//Ҳ������ BOOST_STATIC_ASSERT ��ִ���������
	//BOOST_STATIC_ASSERT(sizeof(T));
	delete t;
}


class some_class;
/*
ɾ��һ����̬����Ķ���ʱ�����������������������
�����������ǲ������ģ���ֻ������û�ж��壬��ô�����������ܻ�û�����á�
����һ��Ǳ�ڵ�Σ��״̬������Ӧ�ñ�����
*/
//��������������ָ��������δ��������͡�
some_class* create()
{
	return (some_class*)0;
}

int mainwerwerwq()
{
	some_class* p = create();
	//boost::checked_delete(p);
	//my_checked_delete(p);
	system("pause");
	return 0;
}