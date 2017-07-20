#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "mysort.h"
/////////////////////////////////归并排序结构版/////////////////////////////////////////

/*合并算法*/
void Merge(int SR[], int TR[], int i, int m, int n)
{
	int j;
	int k;
	int l;
	for (j = m + 1, k = i; i <= m && j <= n; k++)
	{
		if (SR[i] < SR[j])
		{
			TR[k] = SR[i++];
		}
		else
		{
			TR[k] = SR[j++];
		}
	}
	if (i <= m)
	{
		for (l = 0; l <= m - i; l++)
		{
			TR[k + l] = SR[i + l];
		}
	}
	if (j <= n)
	{
		for (l = 0; l <= n - j; l++)
		{
			TR[k + l] = SR[j + l];
		}
	}
}

void MSort(int SR[], int TR1[], int s, int t)
{
	int m;
	int TR2[MAXSIZE + 1];
	if (s == t)
	{
		TR1[s] = SR[s];
	}
	else
	{
		m = (s + t) / 2;
		MSort(SR, TR2, s, m);
		MSort(SR, TR2, m + 1, t);
		Merge(TR2, TR1, s, m, t);
	}
}

void MergeSort(SqList* L)
{
	MSort(L->r, L->r, 1, L->length);
}

/////////////////////////非递归归并排序结构版/////////////////////////////////////////////////
MergePass(int SR[], int TR[], int s, int n)
{
	int i = 1;
	int j = 0;;

	while (i <= n - 2 * s - 1)
	{
		Merge(SR, TR, i, i + s - 1, i + 2 * s - 1);
		i = i + 2 * s;
	}

	if (i < n - s + 1)
	{
		Merge(SR, TR, i, i + s - 1, n);
	}
	else
	{
		for (j = i; j <= n; j++)
		{
			TR[j] = SR[j];
		}
	}
}

void MergerSort_digui(SqList* L)
{
	int* TR = (int*)malloc(sizeof(int)*L->length);
	int k = 1;
	while (k < L->length)
	{
		MergePass(L->r, TR, k, L->length);
		k = 2 * k;
		MergePass(TR, L->r, k, L->length);
		k = 2 * k;
	}
}






////////////////////////////数组版递归归并排序//////////////////////////////////////////////

/*归并方法*/
void Merge2(int SR[], int TR[], int i, int m, int n)
{
	int j;
	int k;
	int l;
	for (j = m + 1, k = i; i <= m && j <= n; k++)//归并
	{
		if (SR[i] < SR[j])
		{
			TR[k] = SR[i++];
		}
		else
		{
			TR[k] = SR[j++];
		}
	}
	if (i <= m)//链接多余的SR[i..]元素
	{
		for (l = 0; l <= m - i; l++)
		{
			TR[k + l] = SR[i + l];
		}
	}
	if (j <= n)//链接多余的SR[j...]
	{
		for (l = 0; l <= n - j; l++)
		{
			TR[k + l] = SR[j + l];
		}
	}
}

/*归并排序*/
void MSort2(int SR[], int TR1[], int s, int length)
{
	int m;
	int TR2[MAXSIZE + 1];
	if (s == length)
	{
		TR1[s] = SR[s];
	}
	else
	{
		m = (s + length) / 2;//从序列的中间下标开始拆分
		MSort(SR, TR2, s, m);//拆分左序列
		MSort(SR, TR2, m + 1, length);//拆分右序列
		Merge(TR2, TR1, s, m, length);//左右序列归并
	}
}

void MergeSort2(int* L, int length)
{
	MSort(L, L, 0, length - 1);//数组的最后一个元素不存在，所以减1
}

/////////////////////////数组版非递归归并排序/////////////////////////////////////////////////
void MergePass2(int SR[], int TR[], int s, int n)
{
	int i = 0;//数组从0开始
	int j = 0;

	while (i <= n - 2 * s - 1)
	{
		Merge(SR, TR, i, i + s - 1, i + 2 * s - 1);
		i = i + 2 * s;//加上增量
	}

	if (i < n - s + 1)
	{
		Merge(SR, TR, i, i + s - 1, n);
	}
	else
	{
		for (j = i; j <= n; j++)
		{
			TR[j] = SR[j];
		}
	}
}

void MergerSort_digui2(int* L, int length)
{
	int* TR = (int*)malloc(sizeof(int) * length);
	int k = 1;
	
	while (k < length)
	{
		MergePass2(L, TR, k, length);
		k = 2 * k;
		MergePass2(TR, L, k, length);
		k = 2 * k;
	}
}

void MergerSort_digui_array(int* L, int length)
{
	MergerSort_digui2(L, length - 1);//数组最后一个元素不存在
}


int main(void)
{
	SqList L;
	init(&L);
	Print(L);
	printf("\n");
	//MergeSort(&L);
	MergerSort_digui(&L);
	Print(L);
	printf("\n");

 
	int x[10] = { 50, 10, 90, 30, 70, 40, 80, 60, 20, 100 };
	showArray(x, 10);
	//MergeSort2(x, 10);
	MergerSort_digui_array(x, 10);
	printf("\n");

	showArray(x, 10);
	system("pause");
	return 0;
}