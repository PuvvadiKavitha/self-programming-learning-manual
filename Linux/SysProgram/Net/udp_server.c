#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(8080);

	int serveraddr_len = sizeof(server_addr);
	
	//1.create socket
	int server_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (-1 == server_fd)
	{
		perror("create socket error");
		exit(1);
	}

	//2.bind
	if (-1 == bind(server_fd, (struct sockaddr*)&server_addr, serveraddr_len))
	{
		perror("bind error");
		exit(1);
	}

	//3.option
	char buf[100];
	recvfrom(server_fd, buf, 100, 0, (struct sockaddr*)&server_addr, &serveraddr_len);
	printf("get from client:%s\n", buf);

	//4.close
	close(server_fd);


	return 0;
}
