#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main()
{
	struct sockaddr_in client_addr;
	client_addr.sin_family = AF_INET;
	client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	client_addr.sin_port = htons(8080);

	//1.create socket
	int server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (-1 == server_fd)
	{
		perror("create socket error");
		exit(1);
	}
	
	//2.connect
	if (-1 == connect(server_fd, (struct sockaddr*)&client_addr, sizeof(client_addr)))
	{
		perror("connect error");
		exit(1);
	}

	//3.option
	char buf[100];
//	read(server_fd, buf, 100);
	recv(server_fd, buf, 100, 0);
	printf("receiver from server:%s\n", buf);

	//4.close
	close(server_fd);


	return 0;
}
