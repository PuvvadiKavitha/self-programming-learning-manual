#include <stdio.h>
#include <stdlib.h>

void Fun()
{
	char c;
	
	//static char buf[10];
	//setbuf(stdout, buf);
	
	setbuf(stdout, malloc(BUFSIZ)); 
	
	while ((c = getchar()) != EOF)
		putchar(c);
}

int main(void)
{
	Fun();
	return 0;
}
