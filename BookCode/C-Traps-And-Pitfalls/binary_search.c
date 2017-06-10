#include <stdio.h>
#include <stdlib.h>
#define N 1000
int *bsearch_1(int *p, int n, int num)
{//本算法用于查找有序数组p中的元素num, 采用二分查找法, 并用指针和移位运算来提高查找的效率
	int *low = p;
	int *high = p + n;
	int *mid = NULL;
	while (low < high)
	{
		mid = low + ((high - low) >> 1);//获取中间元素的位置
		if (num < *mid)
		{
			high = mid;//使用数组的不对称边界的思想，不包含上界
		}
		else if (num > *mid)
		{
			low = mid + 1;//使用数组的不对称边界的思想, 包含下界
		}
		else
		{
			return mid;
		} 
	}
	return NULL;
}



int *bsearch_2(int *p, int n, int num)
{//本算法用于查找有序数组p中的元素num, 采用二分查找法, 使用数组来表示, 效率没有bsearch_1高
	int low = 0;
	int high = n;
	int mid = 0;
	while (low < high)
	{
		mid = (high + low) / 2;
		if (num < p[mid])
		{
			high = mid;//使用数组的不对称边界的思想，不包含上界
		}
		else if (num > p[mid])
		{
			low = mid + 1; //使用数组的不对称边界的思想, 包含下界
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

