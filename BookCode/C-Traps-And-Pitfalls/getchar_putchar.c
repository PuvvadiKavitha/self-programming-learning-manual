/*
 * ����stdioͷ�ļ�getchar��putchar��չ��Ϊ��, 
 * ����Ϊ�������ã��������õĿ���Ҫ���ں��չ��
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
