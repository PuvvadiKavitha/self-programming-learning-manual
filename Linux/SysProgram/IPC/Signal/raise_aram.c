#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{	
	int a = 0;
//	alarm(3);
	pause();
	while (1)
	{	
		a++;
	}
	printf("exit\n");
	return 0;
}
