#include <stdio.h>

static int num_of_digits(int num) {
	int n=0;
	for (; num != 0; num /= 10)
		n++;
	
	return n;
}

static int num_of_digits_rec(int num) {
	if (num < 10)
		return 1;
	else
		return 1 + num_of_digits_rec(num / 10);
}

int main() {
	printf("%d\n", num_of_digits(123));
	printf("%d\n", num_of_digits_rec(123));
	return 0;
}