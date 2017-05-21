/**
 * @file Ex_1_1_26.c
 * @synopsis  Ex_1_1_26.c
 * @author cheng-zhi, chengzhihjy@gmail.com
 * @version 1.0
 * @date 2017-05-21
 */
#include <stdio.h>


/**
 * @synopsis  my_swap 
 *
 * @param a
 * @param b
 */
static void my_swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * @synopsis  sort_a_b_c 
 *
 * @param a
 * @param b
 * @param c
 */
static void sort_a_b_c(int a, int b, int c)
{
	if (a > b)
		my_swap(&a, &b);
	if (a > c)
		my_swap(&a, &c);
	if (b > c)
		my_swap(&b, &c);
	printf("a > b > c: %d > %d > %d\n", a, b, c);
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
	sort_a_b_c(2, 1, 3);
	return 0;
}


