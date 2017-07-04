#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
	int server_fd = 0;
	int client_fd = 0;

	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(8080);

	int serveraddr_len = sizeof(server_addr);
	int clientaddr_len = sizeof(client_addr);

	//1.create socket
	if (-1 == (server_fd = socket(AF_INET, SOCK_STREAM, 0)))
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

	//3.listen
	if (-1 == listen(server_fd, 20))
	{
		perror("listen error");
		exit(1);
	}


	//4.accept
	if (-1 == (client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &clientaddr_len)))
	{
		perror("accept error");
		exit(1);
	}

	//5.option
//	write(client_fd, "hello world", 11);
	send(client_fd, "Hello chengzhi", 14, 0);
	printf("send to client ok\n");


	//6.close
	close(server_fd);
	close(client_fd);

	return 0;
}
