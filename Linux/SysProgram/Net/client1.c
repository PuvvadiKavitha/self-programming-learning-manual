#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main()
{
	//server addr
	struct sockaddr_un server_addr;
	server_addr.sun_family = AF_UNIX;
	strcpy(server_addr.sun_path, "socketfile");


	//1.socket create
	int server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
	if (-1 == server_fd)
	{
		perror("socket error");
		exit(1);
	}

	//2.connect->accept
	if (-1 == connect(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)))
	{
		perror("connect error");
		exit(1);
	}

	//3.option
	char buf[100];
	read(server_fd, buf, 100);
	printf("receiver from server:%s\n", buf);	
	//4.close
	close(server_fd);






	return 0;
}

