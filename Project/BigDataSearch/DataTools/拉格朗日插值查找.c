#include <stdio.h>
#include <stdlib.h>

int* lglr_search(int* x, int m, int find_num)
{
	int* low = x;
	int* high = x + m;
	int* mid = NULL;

	while (low < high)
	{
		//(m - *low) / (*high - *low)����Ҫ���ҵ�������ȫ�������еı���
		//������ݾ��ȷ��䣬��ôһ�ξͿ����ҵ�
		//Ҫ�����������ڴ���Գ���
		//1 2 3 4  5  6      ����ֱ��ʹ������Ĳ��Ҽ���   һ���ҵ�
		//1  10 12  14  100  ��������Ҫ�õ��������ղ�ֵ��ʽ������  һ�ο�һ��� ������ҵ�
		//�ٶȰٶ�
		mid = low + (high - low) * (m - *low) / (*high - *low);
		if (*mid < find_num)
		{
			low = mid + 1;
		}
		if (*mid > find_num)
		{
			high = mid;
		}
		if (*mid == find_num)
		{
			return mid;
		}
	}
	return NULL;
}


int main2(void)
{
	int x[] = { 1, 10, 14, 52,  74,  97, 104 };
	printf("%d\n", *lglr_search(x, 7, 10));

	system("pause");
	return 0;
}