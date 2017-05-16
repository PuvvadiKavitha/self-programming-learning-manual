/**
 * @file Ex_1_1_20.c
 * @synopsis  Ex_1_1_20.c
 * @author cheng-zhi, chengzhihjy@gmail.com
 * @version 1.0
 * @date 2017-05-16
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/**
 * @synopsis  my_ln 
 *
 * @param N
 *
 * @return ln(N!)
 *
 * Note:
 * 	ln(N!) = ln(N * (N - 1) * (N - 2) * ... * 1) = ln(N) + ln(N - 1) + ... + ln(1)
 * 	
 * 	0! = 1
 * 	1! = 1
 */
static double my_ln(double N)
{
	if (N <= 1)
		return 0;
	else
		return log(N) + my_ln(N - 1);
}




/**
 * @synopsis  main 
 *
 * @return 
 *
 * Note:
 * 	Compile: gcc Ex_1_1_20.c -std=c99 -lm
 */
int main(void)
{
	for (int i = 0; i < 10; i++)
		printf("ln(%d!) = %f\n", i, my_ln(i));
	return 0;
}


