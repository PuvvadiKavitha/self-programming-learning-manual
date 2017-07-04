#include <stdio.h>
#include <pthread.h>

pthread_t tid[2];


void* fun2(void* arg)
{

	printf("fun2 run...\n");

}


void* fun(void* arg)
{
	pthread_create(&tid[1], NULL, fun2, NULL);
	pthread_join(tid[1], NULL);

}



int main()
{
		
	pthread_create(&tid[0], NULL, fun, NULL);
	pthread_detach(tid[0]);

	getchar();

	return 0;
}













