#include <pthread.h>
#include <stdio.h>

void* thread_fun(void* arg)
{
	printf("Child thread get msg:%s\n", (char*)arg);
	//exit
	pthread_exit("bye");
}



int main()
{
	//create thread
	pthread_t mythread;
	char message[] = "hello chengzhi";
	if (0 == pthread_create(&mythread, NULL, thread_fun,(void*)message))
	{
		printf("thread create success\n");
	}
	void* retval = NULL;
	//join
	pthread_join(mythread, &retval);
	printf("Main Thread get result:%s\n", (char*)retval);


	return 0;
}
