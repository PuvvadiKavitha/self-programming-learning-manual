#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char hello[] = "hello";
	
	printf("%p\n", hello);

	printf("%c\n", hello);//��Ч�ַ�
	
	printf("%c\n", &hello[0]);//��Ч�ַ�
	
	printf("%s\n", hello);
	
	printf("%s\n", &hello[0]);

	return 0;
}

