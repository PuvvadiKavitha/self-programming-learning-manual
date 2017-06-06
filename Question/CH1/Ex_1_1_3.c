#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	if (argc < 4)
	{
		printf("Usage: ./a.out 1 2 3\n");
		return -1;
	}

	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	int c = atoi(argv[3]);

	//printf("%d, %d, %d\n", a, b, c);
	if ((a == b) && (a == c))
	{
		printf("equal\n");
	}
	else 
	{
		printf("not equal\n");
	}

	return 0;
}
