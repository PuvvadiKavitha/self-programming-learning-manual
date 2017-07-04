#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		perror("argc < 2");
		exit(1);
	}
	struct hostent* myhost;
	myhost = gethostbyname(argv[1]);
	if (NULL == myhost)
	{
		perror("get host by name error");
		exit(1);
	}


	struct sockaddr_in client_addr;
	client_addr.sin_family = AF_INET;
	client_addr.sin_addr = *((struct in_addr*)(myhost->h_addr));
	client_addr.sin_port = htons(8080);

	//1.socket
	int server_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (-1 == server_fd)
	{
		perror("socket error");
		exit(1);
	}
	//2.sendto
	sendto(server_fd, "Hello World", 11, 0, (struct sockaddr*)&client_addr, sizeof(client_addr));

	printf("client send ok\n");


	close(server_fd);


	return 0;
}
