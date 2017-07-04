#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid = fork();
	if (0 == pid)
	{
		printf("child process\n");
		sleep(5);
		exit(0);
	}
	else if(pid > 0)
	{
		wait(NULL);
		printf("child has run ok, parent processing...\n");
		exit(0);
	}




	return 0;
}

