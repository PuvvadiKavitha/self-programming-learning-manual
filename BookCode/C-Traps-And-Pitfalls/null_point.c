#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *p = NULL;
	
	/* Output null */
	printf("%c", p);
	/* Output (null) */
	printf("%s", p);
	/* Output null */
	printf(p);
	return 0;
}

