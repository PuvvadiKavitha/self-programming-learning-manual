#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	char* content = "log:chengzhi\n";
	pid_t pid = fork();
	//1.fork
	if (pid < 0)
	{
		exit(1);
	}
	else if(pid > 0)
	{
		exit(0);
	}

	//2.start new session
	setsid();

	//3.close all fd
	int i = 0;
	for(i = 0; i < 200866; i++)
	{
		close(i);
	}

	//4.change dir to /
	chdir("//");

	//5.perssion
	umask(0);

	//6.options
	int fd = 0;
	while (1)
	{
		fd = open("//tmp//chengzhilog.log", O_CREAT | O_RDWR |O_APPEND, 0666);
		if (fd > 0)
		{
			write(fd, content, strlen(content));
			close(fd);
		}

		sleep(2);

	}

	return 0;
}
