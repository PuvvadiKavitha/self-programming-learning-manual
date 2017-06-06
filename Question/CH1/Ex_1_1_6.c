#include <stdio.h>


int main(void)
{
	int f = 0;
	int g = 1;

	for (int i = 0; i <= 15; i++)
	{
		printf("%d\n", f);
		f = f + g;
		g = f - g;
	}


	return 0;
}
