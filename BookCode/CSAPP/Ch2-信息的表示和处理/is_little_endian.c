#include <stdio.h>

int is_little_endian() {
/*
LittleEndian:
x = 1 -> 0x00000001 -> memory:01 00 00 00 -> *(char*)&x -> 01 = 1
BigEndian:
x = 1 -> 0x00000001 -> memory:00 00 00 01 -> *(char*)&x -> 00 = 0
*/
	int x = 1;
	return *((char*)&x);
}

int main() {
	printf("is_little_endian: %d", is_little_endian());
	return 0;
}