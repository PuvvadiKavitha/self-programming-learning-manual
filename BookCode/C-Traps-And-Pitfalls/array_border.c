#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
static char buffer[N];
static char *bufptr = buffer;

void flushbuffer()
{
	for (int i = 0; i < N; i++)
	{
		putchar(buffer[i]);
		buffer[i] = 0;
	}
	
	bufptr = buffer;
}

//内存copy函数
void mymemcpy(char *dest, const char * source, int n)
{
	while (--n >= 0)
		*(dest++) = *(source++);
}

//重要的一个函数
void bufwrite(char *p, int n)
{
	while (n > 0)
	{
		int k;
		int rem;

		if (bufptr == &buffer[N])
		{
			flushbuffer();
		}
		
		//rem = N - (bufptr - buffer);
		rem = (buffer + N) - bufptr;
		k = n > rem ? rem : n;
		
		mymemcpy(bufptr, p, k);
		
		bufptr += k;
		p += k;
		n -= k;
	}

	flushbuffer();
}



int main(void)
{
	char str[] = "chengzhijiayuhello"; 
	bufwrite(str, strlen(str));
	
	putchar('\n');
	return 0;
}
