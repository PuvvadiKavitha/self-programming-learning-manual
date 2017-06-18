#include <stdio.h>
int main() {
	int a = 10;
	int b[10];

	// 4
	printf("sizeof(int)\t: %d\n", sizeof(a));
	
	// 64: 8, 32: 4
	printf("sizeof(int*)\t: %d\n", sizeof(int *));

	// 4 * 10
	printf("sizeof(b)\t: %d\n", sizeof(b));

	// 4
	printf("sizeof(b[0])\t: %d\n", sizeof(b[0]));

	// 4
	printf("sizoef(*b)\t: %d\n", sizeof(*b));

	return 0;
}