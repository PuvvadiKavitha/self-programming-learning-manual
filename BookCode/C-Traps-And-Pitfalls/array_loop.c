#include <stdio.h>
#include <stdlib.h>

#define N 9

int main(void)
{

	int a[N];
	int i;
	
	//VS �²��������ѭ��, i �ĵ�ַ���������������һ��Ԫ�صĺ���
	
	printf("&i = %p, a = %p\n", &i, a);
	
	// �� i �ĵ�ַ���������һ��Ԫ�صĺ���ʱ�����һ��ѭ���Ὣ i ��������Ϊ 0
	// �Ӷ�������ѭ��
	for (i = 0; i <= N; i++)
	{
		a[i] = 0;
		printf("a[%d] = %d\n", i, a[i]);
	}
	
	return 0;
}
