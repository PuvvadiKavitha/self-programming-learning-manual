#include <stdio.h>
#include <unistd.h>

int main()
{
	int count = 0;
	pid_t pid = fork();
	count++;
	if (-1 == pid)
	{
		perror("fork fail");
		
	}
	else if (0 == pid)
	{
		printf("child process count:%d\n", count);
	}
	else
	{
		printf("parent process count:%d\n", count);
	}


	return 0;
}
