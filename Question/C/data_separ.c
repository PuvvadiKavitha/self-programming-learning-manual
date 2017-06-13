#include <stdio.h>


int main() {
	int inum = 0;
	printf("please input inum:");
	scanf("%d", &inum); 

	/* eg: inum = ABC
	 * 	a = inum % 10 = C
	 *  b = (inum % 100) / 10 = B
	 * 	c = inum / 100 = A
	 */
	int a = inum % 10;
	int b = (inum % 100) / 10;
	int c = inum / 100;
	printf("%d + %d + %d = %d\n", a, b, c, a + b + c);

	return 0;
}