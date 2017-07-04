#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("input file name:\n");
		exit(1);
	}
	umask(0);
	int fd = open(argv[1], O_CREAT | O_RDWR, 0666);
	if (fd < 0)
	{
		printf("file open fail\n");
		exit(1);
	}
	else
	{
		printf("success fd = %d\n", fd);
		char buf[] = "hello world\n";
		if (write(fd, buf, strlen(buf)) != -1)
		{
			printf("write success\n");

		}
		else
		{
			printf("write failed\n");
		}
		close(fd);
		printf("file closed\n");
	}

	return 0;
}
















