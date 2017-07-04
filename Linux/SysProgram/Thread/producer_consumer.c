#include <stdio.h>
#include <pthread.h>
#define BUFSIZE 1000
#define OVER -1





struct producons
{
	int buffer[BUFSIZE];
	pthread_mutex_t lock;
	int readpos;
	int writepos;
	pthread_cond_t notempty;
	pthread_cond_t notfull;
}buffer;

void init(struct producons* p)
{
	pthread_mutex_init(&p->lock, NULL);
	pthread_cond_init(&p->notempty, NULL);
	pthread_cond_init(&p->notfull, NULL);
	p->readpos = 0;
	p->writepos = 0;
}

void my_put(struct producons* p, int data)
{
	pthread_mutex_lock(&p->lock);
	if ((p->writepos + 1) % BUFSIZE == p->readpos)
	{
		pthread_cond_wait(&p->notfull, &p->lock);
	}
	p->buffer[p->writepos] = data;
	p->writepos++;
	if (p->writepos >= BUFSIZE)
	{
		p->writepos = 0;
	}

	pthread_cond_signal(&p->notempty);
	pthread_mutex_unlock(&p->lock);




}


int my_get(struct producons* p)
{
	int data = 0;
	pthread_mutex_lock(&p->lock);

	if(p->writepos == p->readpos)
	{
		pthread_cond_wait(&p->notempty, &p->lock);
	}
	data = p->buffer[p->readpos];
	p->readpos++;
	if (p->readpos >= BUFSIZE)
	{
		p->readpos = 0;
	}

	pthread_cond_signal(&p->notfull);
	pthread_mutex_unlock(&p->lock);

	return data;
}


void* producer(void* data)
{
	int n = 0;
	while (n < 10000)
	{
		printf("%d \n", n);
		my_put(&buffer, n);
		n++;

	}
	my_put(&buffer, OVER);
	return NULL;
}


void* consumer(void* data)
{
	int d = 0;
	while (1)
	{
		d = my_get(&buffer);
		if (OVER == d)
		{
			break;
		}
		printf("%d \n", d);

	}
	return NULL;
}



int main()
{

	pthread_t thread_a;
	pthread_t thread_b;
	void* retval = NULL;
	init(&buffer);
	pthread_create(&thread_a, NULL, producer, 0);
	pthread_create(&thread_b, NULL, consumer, 0);
	pthread_join(thread_a, &retval);
	pthread_join(thread_b, &retval);
	

	return 0;
}
