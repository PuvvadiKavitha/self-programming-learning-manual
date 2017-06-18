#include <stdio.h>

static int add(int a, int b) {
	return a + b;
}

static int sub(int a, int b) {
	return a - b;
}

void main() {
	// Define function pointer array.
	int(*p[2])(int a, int b);

	p[0] = add;
	p[1] = sub;

	// Call function.
	for (int i = 0; i < 2; i++)
		printf("%d\n", p[i](4,1));
}