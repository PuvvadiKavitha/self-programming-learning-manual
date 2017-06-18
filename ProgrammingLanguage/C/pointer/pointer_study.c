#include <stdio.h>
#include <stdlib.h>

void main() {

#if 1
	int *p = NULL;
	// Don`t input a illegal memory address.
	scanf("%p", &p);
	*p = 5;
	printf("*p = %d\n", *p);
#endif

#if 0
	char *p = "abc";//p是一个指针 存储字符串的首地址
	char str[10] = "abc";
	// 32:4, 64:8, 10
	printf("%d %d\n", sizeof(p), sizeof(str));
	
	//*p = 'A'; //指针地址常量不可以修改
	str[0] = 'A';//数组是变量可以修改
	// abc, Abc
	printf("%s %s", p, str); 
#endif

#if 0
	// NULL pointer
	double  *p = NULL;
	// NULL data
	double  *p; 
	*p = NULL;  
	
	// Add pointer
	*p++ == *(p++)
	// Add data 
	(*p)++;
#endif
}

void main1() {
	int num = 100;
	//int* p = NULL;
	//p = &num;

	#define NULL  ((void *)0)
	// Can compile, but don`t run.
	int* p = num;
	printf("%d\n", *p);
}