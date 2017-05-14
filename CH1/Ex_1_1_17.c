/**
 * @file Ex_1_1_17.c
 * @synopsis  Ex_1_1_17.c
 * @author cheng-zhi, chengzhihjy@gmail.com
 * @version 1.0
 * @date 2017-05-14
 */
#include <stdio.h>
#include <stdlib.h>


/**
 * @synopsis  exR2 
 *
 * @param n
 *
 * @return  the sum of exR2(n - 3) + n + exR2(n - 2) + n 
 *
 * Note:
 * 	This fun has bug, stackoverflow !
 */
static int exR2(int n)
{
	int sum = exR2(n - 3) + n + exR2(n - 2) + n;
	
	if (n <= 0)
		return 0;

	return sum;
}


/**
 * @synopsis  main 
 *
 * @return   
 */
int main(void)
{
	printf("sum = %d\n", exR2(6));

	return 0;
}


