#include <stdio.h>
#include <stdlib.h>


/*
 * This function show a bool array, when array value = true, then show `*`
 * else show ` `.
 * x is the array row num, y is array colum num, boo_array is array pointer.
 * eg:
 *	show_bool_array(3, 3, bool_array);
 */
static void show_bool_array(const int x, const int y, int bool_array[x][y])
{
	// Print colum num .
	for (int k = 0; k <= x; k++)
		printf("%d\t", k);

	putchar('\n');

	for (int i = 0; i < x; i++)
	{
		//Print row num .
		printf("%d\t", i + 1);
		for (int j = 0; j < y; j++)
		{
			//Print array value .
			if (bool_array[i][j])
				printf("*\t");
			else
				printf(" \t");
		}
		putchar('\n');
	}	


}



int main(void)
{
	int A[3][3] = {1, 1, 0, 0, 1, 1, 1, 1, 1};

	show_bool_array(3, 3, A);

	return 0;
}





