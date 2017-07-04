#include <stdio.h>
#include <stdlib.h>

int main()
{
	umask(0);
	chmod(".//1.txt", 0666);
	return 0;
}
