#include <stdio.h>

int b = 20;
char ch = 'a';

//一个函数可以返回一个整型值、字符值、实型值等，也可以返回指针型的数据，
//即地址。其概念与以前类似，只是返回的值的类型是指针类型而已


/*
 * A functionc can return int, char ..., and else can return pointer type.
 */
int* go() { 
	return &b; 
}

char* gogo() {
	return &ch;
}

void main() {
	printf("b = %d\n", *(go()));
	printf("ch = %c\n", *(gogo()));	 
}