#include <stdio.h>
#include <stdlib.h>


int main3() {
	// Octal 
	int num = 010;
	printf("%d\n", num);
	
	int a = 0x12345678;
	printf("%p\n", &a);
	return 0;
}


int main2() {
	int num = 1;

	//0000 0000 0000 0001 内存中按照这种方式
	//1000 0000 0000 0000
	printf("%lu\n", sizeof(num));
	printf("\n%p", &num);
	return 0;	
}


// &  1&1 = 1	1&0 = 0	0&0 = 0 0&1 = 1
int  main1()
{
	int num = 1234567;
	//1234567 取出低8位
	//0000 0000 0001 0010  1101 0110 1000 0111
	//0000 0000 0000 0000  0000 0000 1111 1111  255
	//0000 0000 0000 0000  0000 0000 1000 0111
	printf("%d\n", num & 255);
	return 0;
}
