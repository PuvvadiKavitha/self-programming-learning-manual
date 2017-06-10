/*
 * 加上stdio头文件getchar和putchar被展开为宏, 
 * 否则为函数调用，函数调用的开销要大于宏的展开
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	register int c;

	while ((c = getchar()) != EOF)
		putchar(c);
	
	return 0;
}
