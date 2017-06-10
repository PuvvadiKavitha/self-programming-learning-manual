#include <stdio.h>
#include <stdlib.h>

#define myabs(x) 	(((x) >= 0) ? (x) : (-x))
#define mymax(a, b) ((a) > (b)  ? (a) : (b))


int main(void)
{
	printf("%d\n", myabs(-1));
	
	printf("%d", mymax(1, 3));
	
	return 0;
}
