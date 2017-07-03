#include <stdio.h>
#include <stdlib.h>

int* lglr_search(int* x, int m, int find_num)
{
	int* low = x;
	int* high = x + m;
	int* mid = NULL;

	while (low < high)
	{
		//(m - *low) / (*high - *low)代表要查找的数字在全部数据中的比例
		//如果数据均匀分配，那么一次就可以找到
		//要查找数据在内存相对长度
		//1 2 3 4  5  6      均匀直接使用上面的查找即可   一次找到
		//1  10 12  14  100  不均匀需要用到拉格朗日插值公式来查找  一次砍一大半 多次能找到
		//百度百度
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