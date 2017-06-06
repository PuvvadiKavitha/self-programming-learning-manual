#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int sum = 0;
	
	//2 ^ 0 - 2 ^ 9(1024)
	for (int i = 1; i < 1000; i *= 2)
		for (int j = 0; j < 1000; j++)//1000
			sum++;
	
	//10000
	printf("sum = %d\n", sum);

	return 0;
}

