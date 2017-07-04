#include <stdio.h>
#include <signal.h>
int main()
{
	kill(3434, SIGKILL);
	printf("Has Kill\n");
	return 0;
}
