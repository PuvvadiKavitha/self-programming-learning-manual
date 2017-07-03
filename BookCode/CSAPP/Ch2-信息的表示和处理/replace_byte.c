#include <stdio.h>

typedef unsigned char* byte_pointer;
void show_bytes(byte_pointer start, int len) {
	for (int i = 0; i < len; i++) {
		printf(" %.2x", start[i]);
	}
	printf("\n");
}

void show_int(int x) {
	show_bytes((byte_pointer)&x, sizeof(int));
}


/*
0x12345678
     &
0x11001111 = ~(0xFF << (i << 3) = [00110000])
     |
0x12005678 
     |
0x00AB0000
     |
0x12AB5678
*/

unsigned int replace_byte(unsigned int x, unsigned char b, int i) {
	//return  (x & ~(0xFF << (i * 8))) | (b << (i * 8));
	return  (x & ~(0xFF << (i << 3))) | (b << (i << 3));
}


int main() {
	int x = 0x12345678;
	//show_int(replace_byte(x, 0xAB, 2));
	show_int(replace_byte(x, 0xAB, 0));
	 
	return 0;
}