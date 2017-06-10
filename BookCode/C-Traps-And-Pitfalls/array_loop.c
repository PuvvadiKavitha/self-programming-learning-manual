#include <stdio.h>
#include <stdlib.h>

#define N 9

int main(void)
{

	int a[N];
	int i;
	
	//VS 下不会出现死循环, i 的地址不紧接着数组最后一个元素的后面
	
	printf("&i = %p, a = %p\n", &i, a);
	
	// 当 i 的地址在数组最后一个元素的后面时，最后一次循环会将 i 重新设置为 0
	// 从而导致死循环
	for (i = 0; i <= N; i++)
	{
		a[i] = 0;
		printf("a[%d] = %d\n", i, a[i]);
	}
	
	return 0;
}
