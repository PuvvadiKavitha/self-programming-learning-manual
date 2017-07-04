#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	pid_t pid = vfork();
	if (-1 == pid)
	{
		perror("fork fail");
		
	}
	else if (0 == pid)
	{
		printf("child process:%d\n", getpid());
		exit(0);
	}
	else
	{
		printf("parent process:%d\n", getpid());
		exit(0);
	}


	return 0;
}
