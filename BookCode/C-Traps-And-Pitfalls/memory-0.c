#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *p = NULL;
	/* 访问空指针，未定义错误 */
	printf("%d", *p);
	return 0;
}
