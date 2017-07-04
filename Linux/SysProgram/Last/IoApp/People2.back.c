#include "Act.h"

long GeneralId(){
	long id=0;
	int len=0;
	int fd=open("id.dat",O_RDWR|O_CREAT,0666);
	if(fd<0){
		printf("open id.dat fail\n");
		return -1;
	}
	len=read(fd,&id,sizeof(long));
	if(len>0){
		lseek(fd,0,SEEK_SET);
	}
	long temp=id+1;
	write(fd,&temp,sizeof(long));
	close(fd);
	return id;
}

int getUserFileNameById(char* name,int len,long id){
	char temp[100];
	memset(temp,0,sizeof(temp));
	char* pf="data/%d.dat";
	sprintf(temp,pf,id);
	if(strlen(temp)<len){
		strcpy(name,temp);
		return 0;
	}else{
		printf("filename space is not enough\n");
		return -1;
	}
}

int createAct(struct Act* p){
	char fname[100];
	memset(fname,0,sizeof(fname));
	int fnamevalue;
	fnamevalue = getUserFileNameById(fname,100,p->id);
	if(fnamevalue!=0){
		printf("can't get act filename\n");
		return -1;	
	}
	printf("fname = %s\n", fname);
	int fd=open(fname,O_WRONLY|O_CREAT|O_EXCL,0666);
	if(fd<0){
		printf("open file error!\n");
		return -1;
	}
	write(fd,p,sizeof(p));
	close(fd);
	return 0;
}


int queryAct(struct Act* p, long id, char* pwd)
{
	char file_name[100];
	memset(file_name, 0, 100);
	int file_name_value = getUserFileNameById(file_name, 100, id);
	if (file_name_value != 0)
	{
		printf("Get act file name fail\n");
		return -1;
	}
	
	if (access(file_name, F_OK) != 0)
	{
		printf("The act file name %s is no exist\n", file_name);
		return -1;
	}

	int fd = open(file_name, O_RDONLY);
	if (-1 == fd)
	{
		printf("open file error");
		return -1;
	}

	if (0 == read(fd, p, sizeof(struct Act)))
	{
		printf("query:read error\n");
		return -1;
	}


	if (0 == strcmp(pwd, p->password))
	{
		printf("can query\n");
		return 0;
	}
	else
	{
		printf("psswd is error\n");
		return 3;
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

int saveBalance(struct Act* p, long id, float sal)
{
	char file_name[100];
	memset(file_name, 0, 100);
	int file_name_value = getUserFileNameById(file_name, 100, id);
	if (file_name_value != 0)
	{
		printf("Get act file name fail\n");
		return -1;
	}
	
	if (access(file_name, F_OK) != 0)
	{
		printf("The act file name %s is no exist\n", file_name);
		return -1;
	}

	int fd = open(file_name, O_RDWR);
	if (read(fd, p, sizeof(struct Act) > 0))
	{
		lseek(fd, 0, SEEK_SET);
	}

	p->balance += sal;
    if(-1 == write(fd, p, sizeof(struct Act)))
	{
		printf("save sal faile\n");
		return -1;
	}
	close(fd);
	return 0;
}


int withdraw(struct Act* p, long id, char* pwd, float sal)
{
	char file_name[100];
	memset(file_name, 0, 100);
	int file_name_value = getUserFileNameById(file_name, 100, id);
	if (file_name_value != 0)
	{
		printf("Get act file name fail\n");
		return -1;
	}
	
	if (access(file_name, F_OK) != 0)
	{
		printf("The act file name %s is no exist\n", file_name);
		return -1;
	}

	int fd = open(file_name, O_RDWR);
	if (strcmp(pwd, p->password) != 0)
	{
		printf("password is error\n");
		return 3;
	}
	if (read(fd, p, sizeof(struct Act) > 0))
	{
		lseek(fd, 0, SEEK_SET);
	}

	p->balance -= sal;
    if(-1 == write(fd, p, sizeof(struct Act)))
	{
		printf("withdraw is error:wirte");
		return -1;
	}
	close(fd);
	return 0;
}

int transfer(struct Act* p, long fromid, char* pwd, float bal, long toid)
{
	char file_name1[100];
	memset(file_name1, 0, 100);
	char file_name2[100];
	memset(file_name2, 0, 100);
	int file_value1 = getUserFileNameById(file_name1, 100, fromid);
	int file_value2 = getUserFileNameById(file_name2, 100, toid);

	if (file_value1 != 0)
	{
		printf("The from id can not get file name\n");
		return -1;
	}

	if (file_value2 != 0)
	{
		printf("The to id can not get file name\n");
		return -1;
	}

	if (access(file_name1, F_OK) != 0)
	{
		printf("The from file %s is not exist\n", file_name1);
		return -1;
	}

	if (access(file_name2, F_OK) != 0)
	{
		printf("The to file %s is not exist\n", file_name2);
		return -1;
	}

	int fd_r = open(file_name1, O_RDWR);
	if (-1 == fd_r)
	{
		printf("From file open fail\n");
		return -1;
	}
	
	struct Act ptemp;
	if (read(fd_r, &ptemp, sizeof(ptemp)) >0)
	{
		lseek(fd_r, 0, SEEK_SET);
	}

	if (strcmp(pwd, ptemp.password) != 0)
	{
		printf("From file password is error\n");
		return -1;
	}

	ptemp.balance -= bal;
	write(fd_r, &ptemp, sizeof(ptemp));
	close(fd_r);

	int fd_w = open(file_name2, O_RDWR);
	if (read(fd_w, p, sizeof(struct Act)) > 0)
	{
		lseek(fd_w, 0, SEEK_SET);
	}

	p->balance += bal;
	write(fd_w, p, sizeof(struct Act));
	close(fd_w);
	return 0;
}




int main()
{
	/*
	GeneralId();
	struct Act act;
	act.id = 1;
	strcpy(act.name, "chengzhi");
	strcpy(act.password, "123456789");
	strcpy(act.sex, "male");
	act.age = 20;
	strcpy(act.tel, "18576400712");
	strcpy(act.address, "NCHU_603");
	act.balance = 5000.256;

	createAct(&act);
	*/
	showMenu();
	return 0;

}








