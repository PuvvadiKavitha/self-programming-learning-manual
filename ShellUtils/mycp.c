#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>


#define BUF_SIZE 4096
#define OUTPUT_MODE 0600


/**
 * gcc mycp.c
 * Usage: ./a.out mycp.c mycp.c.bak
 */
int main(int argc, char **argv)
{
	if (argc != 3)
		exit(1);

	int in_fd = 0;
	int out_fd = 0;
	int rd_count = 0;
	int wt_count = 0;
	char buffer[BUF_SIZE] = { 0 };


	/* Open source file. */
	in_fd = open(argv[1], O_RDONLY);
	if (in_fd < 0)
		exit(2);

	/* Create dest file. */
	out_fd = creat(argv[2], OUTPUT_MODE);
	if (out_fd < 0)
		exit(3);

	/* Start copy... */
	while (1) {
	  rd_count = read(in_fd, buffer, BUF_SIZE);
	  if (rd_count <= 0)
		  break;
	  
	  wt_count = write(out_fd, buffer, rd_count);
	  if (wt_count < 0)
		  exit(4);
	}

	/* Don`t to close fd. */
	close(in_fd);
	close(out_fd);

	if (rd_count == 0)
		return 0;
	else 
		exit(5);

}
