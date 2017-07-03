#include <stdio.h>

typedef unsigned char* byte_pointer;

/*打印出一个数所占的字节数*/
void show_bytes(byte_pointer start, int len) {
	for (int i = 0; i < len; i++) {
		printf(" %.2x", start[i]);
	}
	printf("\n");
}

void show_int(int x) {
	show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x) {
	show_bytes((byte_pointer)&x, sizeof(float));
}

void show_double(double x) {
	show_bytes((byte_pointer)&x, sizeof(double));
}

void show_pointer(void* x) {
	show_bytes((byte_pointer)&x, sizeof(void*));
}

void show_short(short x) {
	show_bytes((byte_pointer)&x, sizeof(short));
}

void show_long(long x) {
	show_bytes((byte_pointer)&x, sizeof(long));
}

void show_long_long(long long x) {
	show_bytes((byte_pointer)&x, sizeof(long long));
}

void show_char(char x) {
	show_bytes((byte_pointer)&x, sizeof(char));
}

int main() {
	//0x01
	char char_c = 1;
	show_char(char_c);//01

	//0x00000001
	int int_x = 1;//01 00 00 00 = 4B
	show_int(int_x); 
	
	//0x3f800000
	float float_x = 1.0;//00 00 80 3f = 4B
	show_float(float_x);
	
	//0x000000000000f03f
	double double_x = 1.0;//00 00 00 00 00 00 f0 3f = 8B
	show_double(double_x);
	
	//0x002cfec4
	void* p = &float_x;//c4 fe 2c 00 = 4B
	show_pointer(p);

	//0x0001
	short short_x = 1;//01 00 = 2B
	show_short(short_x);
	
	//0x00000001
	long long_x = 1;//01 00 00 00 = 4B
	show_long(long_x);
	
	//0x0000000000000001
	long long long_long_x = 1;//01 00 00 00 00 00 00 00 = 8B
	show_long_long(long_long_x);
	return 0;
}