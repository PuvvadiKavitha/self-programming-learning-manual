#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Reverse src
 * Note:
 *	When you don`t use the return value you have to free it.
 */
static char *reverse_string(const char *src) { 
	int len = strlen(src);

	// Don`t forget add '\0'
	// char* dest = (char*)malloc(len);
	char *dest = (char*)malloc(len + 1);
	
	char *d = dest;
	//char* s = &src[len - 1];
	char *s = src + len - 1;

	while (len--)
		*d++ = *s--;
	
	*d = '\0';
	return dest;
}



void main() {
	char* src = "hello world";
	printf("        src = %s\n", src);
	char *reverse_src = reverse_string(src);
	printf("reverse src = %s\n", reverse_src);
	free(reverse_src);
}