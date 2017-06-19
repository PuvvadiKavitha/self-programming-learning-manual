#include <stdio.h>
#include <stdlib.h>
void main() { 
	int num = 10;
	// %x show a number of hex.
	printf("10 %%x = %x\n", num);
	// %x show a number of memory address.
	printf("10 %%p = %p\n", &num);
}