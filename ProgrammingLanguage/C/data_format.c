#include <stdio.h>
int main() {
	float m = 1234.123;
	
	printf("%8.3f\n", m);	// 1234.123
	// Add -, add space to right.
	printf("%-10.3f\n", m);	// 1234.123
	// Default add space to left.
	printf("%10.3f\n", m);	//   1234.123
	
	int x;
	float y;
	char ch;
	//scanf("x=%d,y=%f", &x, &y);//scanf可以按照格式输入
	scanf("%d%c", &x, &ch);//字符与数字之间不用空格 会吧空格当做输入
	printf("%d %c", x, ch);
	
	return 0;
}