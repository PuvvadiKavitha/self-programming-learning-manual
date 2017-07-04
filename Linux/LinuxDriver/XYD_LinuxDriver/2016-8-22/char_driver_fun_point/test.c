#include <stdio.h>
#include <fcntl.h>

int main()
{
    int pfd = open("/dev/char_driver_fun_point", O_CREAT, 0x666);
    close(pfd);

    return 0;
}




