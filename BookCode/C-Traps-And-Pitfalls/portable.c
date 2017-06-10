#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//可移植性较差的版本
void printnum(long n, void(*p)())
{
	if (n < 0)
	{
		(*p)('-');
		n = -n;
	}
	if (n >= 10)
	{
		printnum(n / 10, p);
	}
	(*p)((int)(n % 10) + '0');
}


void printneg(long n, void(*p)())
{
	if (n <= -10)
	{
		printneg(n / 10, p);
	}
	(*p)("0123456789"[-(n % 10)]);
}

void printnum_2(long n, void(*p)())
{
	if (n < 0)
	{
		(*p)('-');
		printneg(n, p);
	}
	else
	{
		printneg(-n, p);
	}
}


int main(void)
{ 
	printf("%c\n", ("0123456789"[0]));
	printf("%c\n", *(&("0123456789"[0]) + 1));
	printf("%c\n", ("0123456789"[2]) + 1);
	printf("%p\n", &("0123456789"[2]));
	return 0;
}
