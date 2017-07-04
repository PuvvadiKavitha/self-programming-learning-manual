#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main()
{
	umask(0);
	int ret = unlink(".//1.txt");
	if (0 == ret)
	{
		printf("success\n");

	}




	return 0;
}
