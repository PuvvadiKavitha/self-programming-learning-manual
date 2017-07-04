#include "bank_msg.h"

void makeDaemon()
{
	pid_t pid = fork();
	if (pid < 0)
	{
		exit(1);
	}
	else if (pid > 0)
	{
		exit(2);
	}
	setsid();
	int i = 0;
	while (i < 200866)
	{
		close(i);
		i++;
	}
	chdir("//");
	umask(0);
}


long GeneralId()
{
	int fd = open("actid.dat", O_CREAT | O_RDWR, 0666);
	if (fd < 0)
	{
		puts("GeneralId:open or create actid.dat error");
		exit(1);
	}
	long id = 0;
	int len = read(fd, &id, sizeof(long));
	if (len > 0)
	{
		lseek(fd, 0, SEEK_SET);
	}
	long temp = id + 1;
	write(fd, &temp, sizeof(long));
	close(fd);
	return id;
}


int getNameById(char* file_name, int len, long id)
{
	char temp_file_name[50];
	memset(temp_file_name, 0, sizeof(temp_file_name));
	char* pf = "data/%d.dat";
	sprintf(temp_file_name, pf, id);
	if (strlen(temp_file_name) < len)
	{
		puts("GetNameById:Get act file ok");
		return 0;
	}
	else
	{
		puts("GetNameById:The act file is too long");
	}

}

int showMenu()
{
     int choice = 0;
     printf("--------ACCOUNT MANAGENT SYSTEN MENU----------------\n");
     printf("---------------1.Create Act-------------------------\n");
     printf("---------------2.Query Act--------------------------\n");
     printf("---------------3.Save Balance-----------------------\n");
     printf("---------------4.Withdraw Balance-------------------\n");
     printf("---------------5.Transer Balance--------------------\n");
     printf("---------------6.Exit System Menu-------------------\n");
     printf("---------------7.Enter You Choice-------------------\n");
     scanf("%d", &choice);
     return choice;
}











