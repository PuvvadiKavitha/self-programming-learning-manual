#include <stdio.h>


int main() {
	int num = 12;
	float num1 = 10.9;

	// ? : operator automatic performs a type conversion.
	printf("%f\n", num > num1 ? num : num1);	// 12.000000

	return 0;
}