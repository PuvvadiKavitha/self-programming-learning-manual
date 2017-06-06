/**
* @file Ex_1_1_14.c
* @synopsis  Ex_1_1_14.c
* @author cheng-zhi, chengzhihjy@gmail.com
* @version 1.0
* @date 2017-05-13
*/
#include <stdio.h>
#include <stdlib.h>

/**
* @synopsis  my_lg 
*
* @param N
*
* @returns i: log2(N) <= i -> 2^i <= N
*/
static int my_lg(int N)
{
	if (N <= 0)
	{
		printf("Note：N > 0\n");
		return 0;
	}

	int x = 1;
	int i = 0;
	while (x <= N)
	{
		x = 2 * x;
		i++;
	}

	return --i;
}




/**
* @synopsis  main 
*
* @param argc
* @param argv
*
* @returns   
*/
int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Usage：./a.out 9\n");
		return -1;
	}

	int N = atoi(argv[1]);

	printf("[log2(%d)] = %d\n", N, my_lg(N));

	return 0;
}

