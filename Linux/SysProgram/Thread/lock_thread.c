#include <pthread.h>
#include <stdio.h>

//static thread lock
pthread_mutex_t mymutex = PTHREAD_MUTEX_INITIALIZER;

void* thread_fun(void* arg)
{
	//lock
	pthread_mutex_lock(&mymutex);
	int i = 0;
	while (i < 3)
	{
		printf("Child thread get i:%d\n",(*((int*)arg)));
		i++;
	}
	//unlock
	pthread_mutex_unlock(&mymutex);


}



int main()
{
	//create thread array
	pthread_t mythread[3];
	int m[3] = {1, 2, 3};
	int i = 0;
	void* retval = NULL;
	while (i < 3)
	{
		pthread_create(&mythread[i], NULL, thread_fun, (void*)&m[i]);
		i++;
//		pthread_join(mythread[i], &retval);
	}

	getchar();

	return 0;
}
