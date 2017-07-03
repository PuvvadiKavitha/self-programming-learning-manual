#include <stdio.h>
#include <stdlib.h>

//二分查找法
int* my_binary_search(int* x, int m, int find_num)
{
	int* low = x;
	int* high = x + m;
	int* mid = NULL;
	 
	while (low < high)
	{
		mid = low + ((high - low) >> 1);
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


int main1(void)
{
	int x[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	printf("%d\n", *my_binary_search(x, 10, 8));

	system("pause");
	return 0;
}