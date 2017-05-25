/**
 * @file Ex_1_1_29.c
 * @synopsis  Ex_1_1_29.c
 * @author cheng-zhi, chengzhihjy@gmail.com
 * @version 1.0
 * @date 2017-05-23
 */
#include <stdio.h>
#include <stdlib.h>


/**
 * @synopsis  rank 
 *
 * @param key
 * @param a[]
 * @param length
 *
 * @return 
 * 	the number of a[i] < key.
 */
static int rank(int key, int a[], int length)
{
	int entry_num = 0;

	for (int i = 0; i < length; i++)
	{
		if (a[i] < key)
			entry_num++;
	}

	return entry_num;
}


/**
 * @synopsis  count 
 *
 * @param key
 * @param a[]
 * @param length
 *
 * @return   
 * 	the number of a[i] == key
 */
static int count(int key, int a[], int length)
{
	int entry_num = 0;

	for (int i = 0; i < length; i++)
	{
		if (a[i] == key)
			entry_num++;
	}

	return entry_num;
}


/**
 * @synopsis  main 
 *
 * @return   
 *
 * Compile:
 * 	gcc Ex_1_1_29.c
 * 	./a.out
 *
 * 	Note:
 *	
 */
int main(void)
{
	int a[10] = {1, 2, 3, 4, 4, 6, 7, 8, 9, 10};
	int i = rank(4, a, 10);
	int j = count(4, a, 10);
	printf("i = %d\n", i);
	printf("j = %d\n", j);

	// a[i, i + j - 1] == key => a[3, 4] = 4
	for (int k = i; k < i + j; k++)
		printf("a[%d] = %d\n", k, a[k]);
	return 0;
}


