#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
int main()
{
    int fd = open("/dev/key_driver", O_CREAT | O_NONBLOCK, 0x666);
    int key_state[4] = {1, 1, 1, 1};
	if (fd < 0)
	{
		printf("File open fail: /dev/key_driver\n");
		return 0;
	}
	else
	{
		printf("fd = %d\n", fd);
	}
	
	fd_set rd_fs;
	int return_num = 0;
	int i = 0;

	while (1)
	{
		FD_ZERO(&rd_fs);
		FD_SET(fd, &rd_fs);
		return_num = select(fd + 1, &rd_fs, NULL, NULL, NULL);
		
		if (return_num < 0)
		{
			printf("Call select fun failed.\n");
			exit(1);
		}
		else if (0 == return_num)
		{
			printf("Select timeout.\n");
		}
		else if (return_num > 0)
		{
			if (FD_ISSET(fd, &rd_fs))
			{
				int ret = read(fd, key_state, sizeof(key_state));
				//printf("main:read ret = %d\n", ret);
				if (ret != sizeof(key_state) / sizeof(int))
				{
					printf("User space read failed.\n");
					continue;
				}
				else
				{
					for (i = 0; i < 4; i++)
					{
						if (0 == key_state[i])
							printf("key[%d] has pressed\n", i);
					}
				}
			}
		}
	}
	close(fd);
	return 0;
}


