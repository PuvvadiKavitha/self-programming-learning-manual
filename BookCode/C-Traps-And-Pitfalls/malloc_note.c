#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *str1 = "chengzhi";
	char *str2 = "hello";
	/* The extar one byte is used to store 0 */
	char *str3 = malloc(strlen(str1) + strlen(str2) + 1);
	
	if (!str3)
	{
		printf("str3 is NULL\n");
		system("pause");
		exit(0);
	}

	strcpy(str3, str1);
	strcat(str3, str2);

	puts(str3);

	free(str3);

	return 0;
}
