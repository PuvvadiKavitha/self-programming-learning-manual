#include <stdio.h>
#include <stdlib.h>
int main()
{
	char ch = 0;
	FILE* fp = NULL;
	char fname[50];
	printf("get name:");
	scanf("%s", fname);
	fp = fopen(".//1.txt", "r");
	if (NULL == fp)
	{
		printf("error\n");
		exit(1);
	}
	while ((ch = getc(fp)) != EOF)
	{
	//	printf("I got the file:%s\n", fname);
		putchar(ch);
	}
	fclose(fp);
	return 0;
}
