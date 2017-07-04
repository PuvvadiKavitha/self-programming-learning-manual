#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	int count = 0;
	pid_t pid = vfork();
	count++;
	if (-1 == pid)
	{
		perror("fork fail");
		
	}
	else if (0 == pid)
	{
		printf("child process count:%d\n", count);
		exit(0);
	}
	else
	{
		printf("parent process count:%d\n", count);
		exit(0);
	}


	return 0;
}
