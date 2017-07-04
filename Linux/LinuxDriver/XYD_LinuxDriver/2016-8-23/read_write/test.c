#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main()
{
    char buffer[200] = "Hello, Everyone";
    int fpd = open("/dev/read_write", O_CREAT | O_RDWR, 0x666);
    int return_num = write(fpd, buffer, strlen(buffer) + 1);
    printf("User Write return num:%d\n", return_num);

    memset(buffer, 0, sizeof(buffer));
    return_num = read(fpd, buffer, 200);

    printf("User read return num = %d\n", return_num);
    printf("User: %s\n", buffer);

    close(fpd); 

    return 0;
}


