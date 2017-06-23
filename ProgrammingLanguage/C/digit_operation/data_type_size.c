#include <stdio.h>

static void show_data_size(void) {
	printf("char               = %d\n", sizeof(char));
	printf("unsigned char      = %d\n", sizeof(unsigned char));
	
	printf("int                = %d\n", sizeof(int));
	printf("unsigned int       = %d\n", sizeof(unsigned int));

	printf("long               = %d\n", sizeof(long));
	printf("unsigned long      = %d\n", sizeof(unsigned long));

	printf("short              = %d\n", sizeof(short));
	printf("unsigned short     = %d\n", sizeof(unsigned short));

	printf("long long          = %d\n", sizeof(long long));
	printf("unsigned long long = %d\n", sizeof(unsigned long long));

	printf("float              = %d\n", sizeof(float));

	printf("double             = %d\n", sizeof(double));
	printf("pointer            = %d\n", sizeof(int *));
}

void main() {
	show_data_size();
}