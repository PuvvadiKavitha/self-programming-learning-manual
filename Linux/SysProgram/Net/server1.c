#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <unistd.h>

int main()
{
	int server_fd = 0;
	int client_fd = 0;
	struct sockaddr_un myaddr;
	struct sockaddr_un clientaddr;

	myaddr.sun_family = AF_UNIX;
	strcpy(myaddr.sun_path, "socketfile");
	
	int serveraddr_len = sizeof(myaddr);
	int clientaddr_len = sizeof(clientaddr);

	//1.socket
	if (-1 == (server_fd = socket(AF_UNIX, SOCK_STREAM, 0)))
	{
		perror("socket error!");
		exit(1);
	}

	//2.bind
	if (-1 == (bind(server_fd, (struct sockaddr*)&myaddr, serveraddr_len)))
	{
		perror("bind error");
		exit(1);
	}

	//3.listen
	if (-1 == (listen(server_fd, 20)))
	{
		perror("listen error");
		exit(1);
	}
	printf("start listen client...\n");
	
	//4.accept
	if (-1 == (client_fd = accept(server_fd, (struct sockaddr*)&clientaddr, &clientaddr_len)))
	{
		perror("accept error");
		exit(1);
	}

	//5.option
	write(client_fd, "hello world", 11);
	printf("send to client ok\n");

	//6.close
	close(server_fd);
	close(client_fd);

	return 0;
}	

