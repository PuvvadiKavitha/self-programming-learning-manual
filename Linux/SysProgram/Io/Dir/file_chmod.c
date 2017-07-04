#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	umask(0);
	int ret = chmod(".//1.txt", 0666);
	if (0 == ret)
	{
		printf("success chmod\n");

	}




	return 0;
}
