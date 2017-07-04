#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int sig_no)
{
	if (SIGINT == sig_no)
	{
		printf("get SIGINT\n");
	}
	else if (SIGQUIT == sig_no)
	{
		printf("get SIGQUIT\n");
	}

}

int main()
{
	printf("wait for signal...\n");
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);

	pause();
	return 0;
}
