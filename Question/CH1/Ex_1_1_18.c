/**
 * @file Ex_1_1_18.c
 * @synopsis  Ex_1_1_18.c
 * @author cheng-zhi, chengzhihjy@gmail.com
 * @version 1.0
 * @date 2017-05-14
 */
#include <stdio.h>
#include <stdlib.h>


/**
 * @synopsis  mystery 
 *
 * @param a
 * @param b
 *
 * @return a * b  
 */
static int mystery(int a, int b)
{
	if (0 == b)
		return 0;
	if (0 == b % 2)
		return mystery(a + a, b / 2);
	return mystery(a + a, b / 2) + a;
}

/**
 * @synopsis  mystery2 
 *
 * @param a
 * @param b
 *
 * @return a ^ b  
 */
static int mystery2(int a, int b)
{
	if (0 == b)
		return 1;
	if (0 == b % 2)
		return mystery2(a * a, b / 2);
	return mystery2(a * a, b / 2) * a;
}

/**
 * @synopsis  main 
 *
 * @return   
 */
int main(int argc, char **argv)
{
	if (argc < 3)
	{
		printf("Usage: ./a.out 2 25\n");
		return -1;
	}

	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	printf("mystery(%d, %d)  = %d\n", a, b, mystery(a, b));
	printf("mystery2(%d, %d) = %d\n", a, b, mystery2(a, b));
	return 0;
}


