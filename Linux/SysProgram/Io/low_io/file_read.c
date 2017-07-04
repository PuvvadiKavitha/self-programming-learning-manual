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
		char buf[1024];
		memset(buf, 0, 1024);
		if (read(fd, buf, 1024) != -1)
		{
			printf("buf = %s\n", buf);
			printf("file length = %d\n",(int)lseek(fd, 0, SEEK_END));
		}
		else
		{
			printf("read failed\n");
		}
		close(fd);
		printf("file closed\n");
	}

	return 0;
}
















