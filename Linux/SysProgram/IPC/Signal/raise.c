#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main()
{
	int pid = 0;
	if (pid = fork() < 0)
	{
		printf("error\n");
	}
	else if(0 == pid)
	{
		printf("child process start\n");
		raise(SIGKILL);
		printf("child process ok\n");
	}
	else
	{
		printf("parent process start\n");
		raise(SIGSTOP);
		printf("parent process ok\n");
	}
	return 0;


}
