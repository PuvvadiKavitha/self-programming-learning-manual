/**
 * @file Ex_1_1_15.c
 * @synopsis  
 * @author cheng-zhi, chengzhihjy@gmail.com
 * @version 1.0
 * @date 2017-05-14
 */
#include <stdio.h>
#include <stdlib.h>



/**
 * @synopsis  histogram 
 *
 * @param a[]: input array
 * @param M: return array size
 *
 * @return: 返回存储次数的数组
 * Note: you need to free the return array when you don`t use it .
 */
static int *histogram(int a[], int M)
{
	// Malloc array that size is M .
	int *result = (int *)malloc(sizeof(int) * M);
	
	if (NULL == result)
	{
		printf("Malloc memory failed!\n");
		return NULL;
	}
	else
	{
		int n = 0;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (i == a[j])
				{
					n++;
				}
			}

			result[i] = n;
			n = 0;
		}

		return result;
	}

}



/**
 * @synopsis  main 
 *
 * @returns   
 */
int main(void)
{
	int a[5] = {0, 1, 3, 3, 4};
	
	printf("     a[]:");
	for (int i = 0; i < 5; i++)
		printf("%d ", a[i]);

	putchar('\n');
	
	int *result = histogram(a, 5);

	printf("result[]:");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", result[i]);
	}
	
	free(result);

	putchar('\n');

	return 0;
}

