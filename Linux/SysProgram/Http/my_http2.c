#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>



int main()
{
	int server_fd = 0;
	int client_fd = 0;
	struct sockaddr_in my_addr;
	struct sockaddr_in client_addr;
	int client_length = sizeof(client_addr);
	char content[48000] = "<html><h1>hello chengzhi</h1></html>";

	my_addr.sin_family = AF_INET;
	my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	my_addr.sin_port = htons(80);

	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (-1 == server_fd)
		perror("socket error!");
	
	if (-1 == bind(server_fd, (struct sockaddr*)&my_addr, sizeof(my_addr)))
		perror("bind error!");

	if (-1 == listen(server_fd, 20))
		perror("listen error!");
	int file_fd = 0;
	while (1)
	{
		printf("start accept...\n");
		client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_length);
		if (-1 == client_fd)
			perror("accept error!");
		printf("client accept\n");

		//return index.html
		file_fd = open("index.html", O_RDWR, 0666);
		if (-1 == file_fd)
			perror("file open faile!");
		memset(content, 0, 48000);
		if (-1 == read(file_fd, content, 48000))
			perror("read error!");

		send(client_fd, content, sizeof(content), 0);
		close(client_fd);
	}
	return 0;
}
