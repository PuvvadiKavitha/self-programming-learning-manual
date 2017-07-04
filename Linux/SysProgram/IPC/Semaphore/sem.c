#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int sem_id = -1;

struct sembuf sem_lock = {0, -1, 0};
struct sembuf sem_unlock = {0, 1, 0};

void lock()
{
	semop(sem_id, &sem_lock, 1);
}

void unlock()
{
	semop(sem_id, &sem_unlock, 1);
}

union semun
{
	int val;
	struct semid_ds* buf;
	unsigned short* array;
	struct seminfo* _buf;
};


int main()
{
	union semun arg;
	arg.val = 1;
	//create sem
	sem_id = semget(55, 1, IPC_CREAT | 0666);
	printf("sem_id = %d\n", sem_id);
	if (sem_id != -1)
	{
		//set sem  =  1
		if(semctl(sem_id, 1, SETVAL, arg) == -1)
		{
			perror("msgctl:");
		}
		printf("lock...\n");
		//lock
		lock();
		printf("hello chengzhi\n");
		sleep(5);
		unlock();
		printf("unlock...\n");
	}
	else
	{
		perror("semget:");
	}

	return 0;
}
