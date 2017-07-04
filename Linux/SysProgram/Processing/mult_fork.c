#include <stdio.h>
#include <unistd.h>

int main()
{
	fork();
	fork();
	fork();
	printf("process:%d\n", getpid());



	return 0;
}	
