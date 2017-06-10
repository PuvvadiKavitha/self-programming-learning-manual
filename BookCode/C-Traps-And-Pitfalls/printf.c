#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int i = 0;
	char c = 0;
	double d = 0;
	
	printf("&i = %p\n", &i);
	printf("&c = %p\n", &c);
	printf("&d = %p\n", &d);
	
	//vs下i和c分配的内存不是连续的而是相隔一个或几个字节
 	for (i = 0; i < 5; i++)
 	{
 		scanf("%d", &c);
 		printf("%d ", i);
 	}

	return 0;
}

