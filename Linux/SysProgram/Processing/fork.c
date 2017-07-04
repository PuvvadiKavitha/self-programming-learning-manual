#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid = fork();
	if (-1 == pid)
	{
		perror("fork fail");
		
	}
	else if (0 == pid)
	{
		printf("child process:%d\n", getpid());
	}
	else
	{
		printf("parent process:%d\n", getpid());
	}


	return 0;
}
