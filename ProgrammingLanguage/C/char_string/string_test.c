#include <stdio.h>
#include <stdlib.h>

//数组没有副本机制 实际参数与形式参数的地址相同
void change(char str[]) { 
	printf("change str = %p\n", str);
}

void main() {
	char str[5] = { 'c','a','l','c' ,'\0'};
	//char str[4] = { "c", "a", "l", "c" }; // Error, using ''

	// Don`t forget '\0'
	printf("str = %d calc = %d\n", sizeof(str), sizeof("calc"));	// 5 5
	
	char *p = str;
	// p = 0x7fffdd057a60, str = 0x7fffdd057a60
	printf("p = %p, str = %p\n", p, str);
	// p = dd057a60, str = DD057A60
	printf("p = %x, str = %X\n", p, str);

	// calc
	for (char *px = p; px < p + 5; px++)
	{
		putchar(*px);
	}

	printf("\n");

	// calc
	for (int i = 0; i < 5;i++)
	{
		putchar(str[i]);
	}

	printf("\n");


	while (*p) {
		putchar(*p);
		p++;
	}  
	printf("\n");

	// main str = 0x7fff8ed61470
	printf("main str = %p\n", str);

	// change str = 0x7fff8ed61470
	change(str);
}