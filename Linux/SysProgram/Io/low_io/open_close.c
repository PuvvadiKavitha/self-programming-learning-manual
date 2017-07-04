#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char* argv[])
{
	if (argc < 2)
	{
	    printf("please input filename:\n");
		exit(1);

	}
	int fd = 0;
	umask(0);
	fd = open(argv[1], O_CREAT | O_RDWR, 0666);
	if (fd < 0)
	{
		printf("error\n");
		exit(1);
	}
	else
	{
		printf("file open success\n");
		close(fd);
		printf("file closed\n");
	}



	return 0;


}
