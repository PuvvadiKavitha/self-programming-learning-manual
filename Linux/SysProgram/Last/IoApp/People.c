#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>


//#include </home/chengzhi/Documentation/Last/IoApp/Act.h>

struct People
{
	char name[30];
	char sex[10];
	int age;
	float sal;

};



int main()
{
	struct People p1;
	strcpy(p1.name, "Tom");
	strcpy(p1.sex, "male");
	p1.age = 20;
	p1.sal = 5000.60;

	struct People p2;
	strcpy(p2.name, "Mary");
	strcpy(p2.sex, "female");
	p2.age = 19;
	p2.sal = 5000.92;

	int fd = open("people.txt", O_CREAT | O_RDWR, 0600);
	if (-1 == fd)
	{
		perror("open error");
		exit(1);
	}

	write(fd, &p1, sizeof(p1));
	write(fd, &p2, sizeof(p2));

	lseek(fd, 0, SEEK_SET);
	struct People ptemp;
	while (read(fd, &ptemp, sizeof(ptemp)) != 0)
	{
		printf("name = %s\nsex = %s\nage = %d\nsal = %f\n", ptemp.name, ptemp.sex, ptemp.age, ptemp.sal);
	}

	close(fd);
	


	return 0;
}














