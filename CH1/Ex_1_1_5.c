#include <stdio.h>
#include <stdlib.h>


static int compare(double d)
{
	if ((d > 0) && (d < 1))
		return 1;
	else
		return 0;
}

int main(int argc, char** argv)
{
	if (argc < 3)
	{
		printf("Usage: ./a.out 0.1 0.3\n");
		return -1;
	}

	double x = strtod(argv[1], NULL);
	double y = strtod(argv[2], NULL);

	if (compare(x) && compare(y))
	{
		printf("true\n");
	}
	else 
	{
		printf("false\n");
	}


	return 0;
}



