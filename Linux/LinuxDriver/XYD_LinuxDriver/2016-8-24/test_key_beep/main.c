#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>


int main()
{
    int fpd = open("/dev/key_beep", O_CREAT | O_RDWR, 0x666);
    printf("fpd = %d\n", fpd);
	while (1)
	{
	//	ioctl(fpd, 2);
	}
	close(fpd);
	return 0;
}


