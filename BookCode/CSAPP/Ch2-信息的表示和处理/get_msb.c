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

/*Get most significant from x
for example:0x12345678 -> 0x12
0x12345678 >> ((sizeof(int) - 1) << 3) = 0x11111112 & 0x000000FF = 0x12
*/
int get_msb(int x) {
	return (x >> ((sizeof(int) - 1) << 3)) & 0xFF;
}


int main() {
	int x = 0x12345678;
	show_int(x);
	show_int(get_msb(x));
	return 0;
}