#include <stdio.h>

void main() {
	char *a[4] = { "calc", "notepad", "write", "mspaint" };
	 
	for (char **p = a; p < a + 4; p++)
		printf("%s\n", *p);
}