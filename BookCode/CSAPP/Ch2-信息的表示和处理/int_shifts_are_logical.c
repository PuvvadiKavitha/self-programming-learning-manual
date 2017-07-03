#include <stdio.h>


int int_shifts_are_logical() {
#if 0
	/*
	如果只有一台机器，则可以将x定义为unsigned int来进行无符号逻辑右移的测试
	unsigned int x = 1;
	*/	
	//0x11 11 11 11
	int x = -1;	
	//x算术右移 -> 0x11 11 11 11
	//x逻辑右移 -> 0x01 11 11 11

	//与 0x10 00 00 00  = 1 << (sizeof(int) << 3) - 1(在int = 4B时，相当于左移31位)相&
	//逻辑!!得到逻辑结果
	return !(!((x >> 1) & (1 << ((sizeof(int) << 3) - 1))));
#endif

#if 1
		int x = ~0;//0x11 11 11 11
		//0x11 11 11 11 == 0x11 11 11 11 -> 1
		//0x01 11 11 11 == 0x11 11 11 11 -> 0
		return (x >> 1) == x;
#endif
}



int main() {
	printf("int_shifts_are_logical: %d", int_shifts_are_logical());
	return 0;
}