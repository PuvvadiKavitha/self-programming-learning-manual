#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    int fd_in = open(".//1.txt", O_RDONLY, 0666);
	int fd_out = open(".//1_back.txt", O_CREAT | O_WRONLY, 0666);
	if (0 == fd_in || 0 == fd_out)
	{
		printf("file open failed\n");
		exit(1);
	}
	char ch = 0;
	while (1 == read(fd_in, &ch, 1))
	{
		write(fd_out, &ch, 1);
	}
	close(fd_in);
	close(fd_out);

	return 0;
}

