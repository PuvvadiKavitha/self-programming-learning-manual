#include <stdio.h>
#include <stdlib.h>
 
int main(void)
{
	char c = '\0';  
	printf("&c = %p\n", &c);
	
	while ((c = getchar()) != EOF)
		putchar(c);
	
	return 0;
}

