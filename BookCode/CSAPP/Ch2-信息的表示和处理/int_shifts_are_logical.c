#include <stdio.h>


int int_shifts_are_logical() {
#if 0
	/*
	���ֻ��һ̨����������Խ�x����Ϊunsigned int�������޷����߼����ƵĲ���
	unsigned int x = 1;
	*/	
	//0x11 11 11 11
	int x = -1;	
	//x�������� -> 0x11 11 11 11
	//x�߼����� -> 0x01 11 11 11

	//�� 0x10 00 00 00  = 1 << (sizeof(int) << 3) - 1(��int = 4Bʱ���൱������31λ)��&
	//�߼�!!�õ��߼����
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