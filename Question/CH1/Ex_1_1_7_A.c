#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
	double t = 9.0;

	while (abs(t - 9.0 / t) > .001)
	{
		t = (9.0 / t + t) / 2.0;
	}
	printf("%.5f\n", t);


	return 0;
}

