/**
 * @file Ex_1_1_19.c
 * @synopsis  Ex_1_1_19.c
 * @author cheng-zhi, chengzhihjy@gmail.com
 * @version 1.0
 * @date 2017-05-16
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @synopsis  F 
 *
 * @param N
 *
 * @return Fibonacci sum
 *
 * Note:
 * 	Using recursive implementate Fibonacci array .
 */
static long F(int N)
{
	if (0 == N)
		return 0;
	if (1 == N)
		return 1;
	return F(N - 1) + F(N - 2);
}


/**
 * @synopsis  F2 
 *
 * @param N
 *
 * @return f[N]
 *
 * Note:
 * 	This function using C array to stroe every entry .
 */
static long F2(int N)
{
	if (0 == N)
		return 0;
	
	if (1 == N)
		return 1;
	
	// Malloc N + 1 int memory, because we need to store f[0] = 0 .
	int *f = (int *)malloc(sizeof(int) * (N + 1));
	if (NULL == f)
	{
		printf("Malloc memory failed!\n");
		return -1;
	}

	// Clear memory .
	memset(f, 0, sizeof(int) * (N + 1));
	
	// Set init value
	f[0] = 0;
	f[1] = 1;

	// a[2] = a[1] + a[0]
	// a[3] = a[2] + a[1]
	// ...
	// a[i] = a[i - 1] + a[i - 2]
	for (int i = 2; i < N + 1; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}
	
	// Because we need to return f[N] and free(f), we need to store f[N] in result .
	int result = f[N];
	
	// Don`t forget .
	free(f);

	return result;

}







/**
 * @synopsis  main 
 *
 * @return   
 */
int main(void)
{
	for (int i = 0; i < 100; i++)
	{
		//printf("%d %ld\n", i, F(i));
		printf("%d %ld\n", i, F2(i));
	}

	return 0;
}


