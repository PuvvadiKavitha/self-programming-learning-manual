#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char hello[] = "hello";
	
	printf("%p\n", hello);

	printf("%c\n", hello);//无效字符
	
	printf("%c\n", &hello[0]);//无效字符
	
	printf("%s\n", hello);
	
	printf("%s\n", &hello[0]);

	return 0;
}

