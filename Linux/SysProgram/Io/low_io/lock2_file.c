#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd = open(".//1.txt", O_RDWR | O_CREAT, 0666);
	if (fd < 0)
	{
		printf("file open fail\n");
		exit(1);
	}

	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_start = 0;
	lock.l_whence = SEEK_SET;
	lock.l_len = 0;
	lock.l_pid = getpid();

	int ret = fcntl(fd, F_SETLKW, &lock);
	printf("return value:%d\n", ret);





	getchar();
	return 0;
}
