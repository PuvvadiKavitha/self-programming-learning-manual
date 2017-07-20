#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *p1, const void *p2) {
	return strcmp(p1, p2);
}


int main() {
	char *str[10] = { "abc", "abd", "bcf", "123", "456", "qwe", "ABC", "ABF", "xyz", "X" };

	qsort(str, sizeof(str) / sizeof(str[0]), sizeof(str[0]), compare);
	
	for (int i = 0; i < 10; i++)
		printf("%s\n", str[i]);
	
	
	return 0;
}
