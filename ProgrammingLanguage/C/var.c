#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main1() {   
	printf("intmax = %d , intmin = %d\n", INT_MAX, INT_MIN);

	printf("uintmax = %u , uintmin = %u\n", UINT_MAX, 0);

	// 4, 7
	printf("%d , %d\n", sizeof("我"), sizeof("我去")); 
	return 0;
}