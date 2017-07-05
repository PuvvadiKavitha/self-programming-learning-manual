#include <stdio.h>
#include <stdlib.h>


void mymemcpy(char *dest, const char *source, int n) {
	while (--n >= 0)
		*(dest++) = *(source++);
}

int main(void)
{
	char dest[50] = { 0 };
	char source[] = "hello world";
	/* 50 12*/
	printf("%d %d\n", sizeof(dest), sizeof(source));
	mymemcpy(dest, source, sizeof(source));
	puts(dest);
	return 0;
}
