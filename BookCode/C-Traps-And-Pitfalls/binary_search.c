#include <stdio.h>
#include <stdlib.h>
#define N 1000
int *bsearch_1(int *p, int n, int num)
{//���㷨���ڲ�����������p�е�Ԫ��num, ���ö��ֲ��ҷ�, ����ָ�����λ��������߲��ҵ�Ч��
	int *low = p;
	int *high = p + n;
	int *mid = NULL;
	while (low < high)
	{
		mid = low + ((high - low) >> 1);//��ȡ�м�Ԫ�ص�λ��
		if (num < *mid)
		{
			high = mid;//ʹ������Ĳ��ԳƱ߽��˼�룬�������Ͻ�
		}
		else if (num > *mid)
		{
			low = mid + 1;//ʹ������Ĳ��ԳƱ߽��˼��, �����½�
		}
		else
		{
			return mid;
		} 
	}
	return NULL;
}



int *bsearch_2(int *p, int n, int num)
{//���㷨���ڲ�����������p�е�Ԫ��num, ���ö��ֲ��ҷ�, ʹ����������ʾ, Ч��û��bsearch_1��
	int low = 0;
	int high = n;
	int mid = 0;
	while (low < high)
	{
		mid = (high + low) / 2;
		if (num < p[mid])
		{
			high = mid;//ʹ������Ĳ��ԳƱ߽��˼�룬�������Ͻ�
		}
		else if (num > p[mid])
		{
			low = mid + 1; //ʹ������Ĳ��ԳƱ߽��˼��, �����½�
		}
		else
		{
			return p + mid;
		}
	} 
	return NULL;
}




int main(void)
{
	int a[N];
	for (int i = 0; i < N; i++)
	{
		a[i] = i + 1;
	}
	int *p = NULL;
	p = bsearch_1(a, N, 30);
	if (p)
	{
		printf("bsearch_1:*p = %d\n", *p);
	} 

	p = bsearch_2(a, N, 30);
	if (p)
	{
		printf("bsearch_2:*p = %d\n", *p);
	}
	return 0;
}

