/**
 * @file Ex_1_1_16.c
 * @synopsis  Ex_1_1_16.c
 * @author cheng-zhi, chengzhihjy@gmail.com
 * @version 1.0
 * @date 2017-05-14
 */
#include <stdio.h>
#include <stdlib.h>


/**
 * @synopsis  exR1 
 *
 * @param n
 *
 * @return  exR1(n -3) + n + exR1(n - 2) + n 
 *
 * Note: 
 * 	In java: the result is "311361142246"
 * 	In C   : the result is the sum of "311361142246" that is 34
 */
static int exR1(int n)
{
	if (n <= 0)
		return 0;
	else
		return exR1(n -3) + n + exR1(n - 2) + n;
}

/**
 * @synopsis  main 
 *
 * @return   
 */
int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Usage: ./a.out 6\n");
		return -1;
	}
	
	int n = atoi(argv[1]);
	printf("exR1(%d) = %d\n", n, exR1(n));

	return 0;
}


