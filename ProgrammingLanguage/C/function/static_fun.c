#include <stdio.h>

//加上static声明该函数的作用域为本文件内
static void go() {
	printf("Hello\n");
}

void main(){
	go();
}
