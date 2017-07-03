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
a = x & 0xFF =  0x000000EF
b = y & ~0xFF = 0x76543200
a | b = 0x765432EF
*/

int NewWord(int x, int y) {
	return (x & 0xFF) | (y & ~0xFF);
}


int main() {
	int x = 0x89ABCDEF;
	int y = 0x76543210;
	show_int(x);
	show_int(y);
	show_int(NewWord(x, y));

	return 0;
}