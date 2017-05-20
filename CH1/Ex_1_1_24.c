/**
 * @file Ex_1_1_24.c
 * @synopsis  Ex_1_1_24.c
 * @author cheng-zhi, chengzhihjy@gmail.com
 * @version 1.0
 * @date 2017-05-20
 */
#include <stdio.h>
#include <stdlib.h>


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

	printf("p = %d\tq = %d\n", p, q);

	int r = p % q;

	return Euclid(q, r);
}



/**
 * @synopsis  main 
 *
 * @return   
 *
 * compile:
 * 	gcc Ex_1_1_24.c
 * 	./a.out 4 2
 */
int main(int argc, char **argv)
{
	if (argc < 3)
	{
		printf("Usage: ./a.out 4 2\n");
		return -1;
	}

	int p = atoi(argv[1]);
	int q = atoi(argv[2]);

	printf("%d\n", Euclid(p, q));

	return 0;
}


