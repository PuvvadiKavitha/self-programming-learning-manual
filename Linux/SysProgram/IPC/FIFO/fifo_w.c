#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#define FIFO_PATH "fifo_file"


int main()
{
	//create fifo
	if (mkfifo(FIFO_PATH, 0666) < 0 && errno != EEXIST)
	{
		perror("create fifo failed");
		return -1;
	}
	else
	{
		printf("create fifo success");
		//open fifo
		int fd = 0;
		char cont_w[] = "hello chengzhi";
		fd = open(FIFO_PATH, O_CREAT|O_WRONLY, 0666);
		if (fd > 0)
		{
			while (1)
			{
				write(fd, cont_w, strlen(cont_w));
				sleep(1);
				printf("write:%s\n", cont_w);
			}
			close(fd);
		}
		else
		{
			perror("open failed");
		}
	
	}
	return 0;
}
