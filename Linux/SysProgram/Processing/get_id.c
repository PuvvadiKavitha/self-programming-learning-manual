#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
	printf("getpid = %d\n", getpid());
	printf("getppid = %d\n", getppid());
	printf("getuid = %d\n", getuid());
	printf("geteuid = %d\n", geteuid());
	printf("getgid = %d\n", getgid());
	printf("getegid = %d\n", getegid());

	return 0;
}
