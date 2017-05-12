#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	//Error: a don`t have been malloc memory !
	//int *a;
	
	// Ok：a has a memory .
	int *a = (int *)malloc(10 * sizeof(int));

	for (int i = 0; i < 10; i++)
		a[i] = i * i;
	
	return 0;
}
