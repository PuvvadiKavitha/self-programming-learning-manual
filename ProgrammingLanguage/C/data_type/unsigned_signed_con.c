#include <stdio.h>

void main() {
	unsigned int a = 6;
	int b = -20;
	// int -> unsigned int => -20 -> a big unsigned int num
	(a + b > 6) ? putchar('1') : putchar('0');
}