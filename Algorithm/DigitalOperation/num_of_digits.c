#include <stdio.h>
static int num_of_digits(int num) {
	int n=0;
	for (; num != 0; num /= 10)
		n++;
	
	return n;
}

int main() {
	printf("%d\n", num_of_digits(123));
	return 0;
}