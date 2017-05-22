/**
* @file Ex_1_1_30.c .c
* @synopsis  Ex_1_1_30.c
* @author cheng-zhi, chengzhihjy@gmail.com
* @version 1.0
* @date 2017-05-22
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * @synopsis  Euclid 
 *
 * @param p
 * @param q
 *
 * @return   
 */
static int Euclid(int p, int q)
{
	if (0 == q)
		return p;

	int r = p % q;

	return Euclid(q, r);
}



static void create_array(int N)
{
	int** a = (int **)malloc(sizeof(int *) * N);
	
	for (int i = 0; i < N; i++)
		a[i] = (int *)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// 最大公约数为 1，则 i 和 j 互质。
			if (1 == Euclid(i, j))
				a[i][j] = 1;
			else
				a[i][j] = 0;
		}
	}
	
	// Output array
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", a[i][j]);
		}

		putchar('\n');
	}



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
		printf("Usage: ./a.out 4\n");
		return -1;
	}

	create_array(atoi(argv[1]));
	return 0;
}


