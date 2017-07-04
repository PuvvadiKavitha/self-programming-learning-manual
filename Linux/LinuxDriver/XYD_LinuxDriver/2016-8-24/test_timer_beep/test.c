#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>


int main()
{
    int fpd = open("/dev/key_beep", O_CREAT | O_RDWR, 0x666);
    printf("fpd = %d\n", fpd);
#if 1 
	int i = 0;
	while (1)
	{
		ioctl(fpd, 2);
		//sleep(1);
		//ioctl(fpd, 0);
		//sleep(1);
		//i++;
	}
#endif
	close(fpd);
	return 0;
}


