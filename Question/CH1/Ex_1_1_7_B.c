#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int sum = 0;

	// (n(n + 1)) / 2
	for (int i = 1; i < 1000; i++)
		for (int j = 0; j < i; j++)
			sum++;

	printf("sum:%d\n", sum);

	return 0;
}

