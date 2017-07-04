#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	//create
	int shm_id = shmget(13, 2048, IPC_CREAT|0666);
	void* shm = NULL;
	if (shm_id != -1)
	{
		//map
		shm = shmat(shm_id, NULL, 0);
		if (shm != (void*)-1)
		{
			//copy
			char str[] = "chengzhi";
			printf("shm = %s\n", (char*)shm);
			printf("success\n");
			shmdt(shm);
		}
		else
		{
			perror("shmat:");
		}
	}
	else
	{
		perror("shmget:");
	}
	return 0;
}

