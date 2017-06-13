#include <stdio.h>
int main1() {
	int a = 2;
	a %= (4 - 1);
	printf("%d, ", a);  //2

	a += a *= a -= a *= 3;//0
	printf("%d", a);
	return 0;
}

int main2() {
	int x, y, z;
	// x = y = 1
	x = y = 1;
	// x = 2, z = 1
	z = ++x - 1;
	printf("%d,%d\n", x, z);// 2 1
	// z = 2, y = 2
	z += y++;
	printf("%d,%d\n", y, z);// 2 2
	return 0;
}

int main3() {
	int x = 02, y = 3;
	// x = 2, y = %d
	printf("x = %d, y = %%d", x, y);
	return 0;
}

int main4() {
	// '6' = 48 + 6, '0' = 48
	char c1 = '6', c2 = '0';
	printf("%d, %d, %c, %c, %d, %d\n", c1, c2, c1, c2, c1 - c2, c1 + c2);
	return 0;
} 

int main() {
	char c;
	int n = 0;;
	printf("please input a char:\n");
	c = getchar();
	n = c - 48;
	printf("%c %d", c, n);
	return 0;
}