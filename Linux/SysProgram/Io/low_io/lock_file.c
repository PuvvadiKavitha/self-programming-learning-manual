#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
int main()
{
	int fd = open(".//1.txt", O_RDWR | O_CREAT, 0666);
	if (fd < 0)
	{
		printf("file open success\n");
		exit(1);
	}
	flock(".//1.txt", LOCK_EX);
	


	getchar();
	return 0;
}
