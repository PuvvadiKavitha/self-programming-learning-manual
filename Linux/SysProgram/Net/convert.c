#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

int main()
{
	struct in_addr my_addr;
	struct hostent* myhost;

	//convert address to net
	inet_aton("192.168.0.1", &my_addr);
    printf("192.168.0.1 address to net is :%d\n", my_addr.s_addr);
	
	printf("address is:%s\n", inet_ntoa(my_addr));

	//gethostbyname
	myhost = gethostbyname("localhost");
	my_addr.s_addr = (uint32_t)(myhost->h_addr);
	printf("localhost ip is %d\n", inet_ntoa(my_addr));













	return 0;
}
