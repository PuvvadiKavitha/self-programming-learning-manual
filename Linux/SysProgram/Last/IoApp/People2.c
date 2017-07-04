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
	return temp;
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


	while (read(fd, p, sizeof(struct Act)) > 0)
	{
		if (0 == strcmp(pwd, p->password))
		{
			printf("can query\n");
			return 0;
		}
	}	
	return 3;

/*
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

*/



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
	struct Act temp_act;

	long temp_id = 0;
	int temp_age = 0;
	float temp_balance = 0;

	char temp_name[30];
	char temp_password[20];
	char temp_sex[10];
	char temp_tel[18];
	char temp_address[300];

	int choice = 0;
	int ret_val = 0;
	long to_id = 0;
	while (1)
	{
		choice = showMenu();
		switch (choice)
		{
			case 1:	printf("---------------1.Create Act-------------------------\n");
				printf("Name: ");
				scanf("%s", temp_name);
				printf("%s\n", temp_name);
	
				printf("Password: ");
				scanf("%s", temp_password);
				printf("%s\n", temp_password);
				
				printf("sex: ");
				scanf("%s", temp_sex);
				printf("%s\n", temp_sex);
				
				printf("tel: ");
				scanf("%s", temp_tel);
				printf("%s\n", temp_tel);
				
				printf("Address: ");
				scanf("%s", temp_address);
				printf("%s\n", temp_address);
				
				printf("Age: ");
				scanf("%d", &temp_age);
				printf("%d\n", temp_age);
				
				printf("Balance: ");
				scanf("%f", &temp_balance);
				printf("%f\n", temp_balance);

				temp_act.id = GeneralId();
				printf("Id: %ld\n", temp_act.id);

				printf("Input Ok\n");
				
				strcpy(temp_act.name, temp_name);
				strcpy(temp_act.password, temp_password);
				strcpy(temp_act.sex, temp_sex);
				strcpy(temp_act.tel, temp_tel);
				strcpy(temp_act.address, temp_address);

				temp_act.age = temp_age;
				temp_act.balance = temp_balance;

				ret_val = createAct(&temp_act);
				if (ret_val != 0)
				{
					printf("Main: 1.create act fail.\n");
					break;

				}
				else
				{
					printf("Main: 1.create act success.\n");
					printf("Main: 1.The act id is %ld.\nName is %s.\n", temp_act.id, temp_act.name);
					printf("Main: 1.Write OK.\n");
					break;
				}

			case 2:	printf("---------------2.Query Act--------------------------\n");
				printf("Input you id:");
				scanf("%ld", &temp_id);
				printf("Input you passsword:");
				scanf("%s", temp_password);
				ret_val = queryAct(&temp_act, temp_id, temp_password);
				
				if (3 == ret_val)
				{
					printf("Main: 2.password is error.\n");
					break;
				}
				else if (-1 == ret_val)
				{
					printf("Main: 2.The act is open or read error.\n");
					break;
				}
				else
				{
					printf("Has query the act:\n");
					printf("Id:%ld\n", temp_act.id);
					printf("Name:%s\n", temp_act.name);
					printf("Sex:%s\n", temp_act.sex);
					printf("Tel:%s\n", temp_act.tel);
					printf("Address:%s\n", temp_act.address);
					printf("Age:%d\n", temp_act.age);
					printf("Balance:%f\n", temp_act.balance);
					printf("Query Ok.\n");
					break;

				}
				
			case 3:	printf("---------------3.Save Balance-----------------------\n");
				printf("Input you id:");
				scanf("%ld", &temp_id);
				printf("Input you balance:");
				scanf("%f", &temp_balance);
			
				ret_val = saveBalance(&temp_act, temp_id, temp_balance);
				
				if (ret_val != 0)
				{
					printf("Main: 3.The act is not exist.\n");
					break;
				}
				else
				{
					printf("Main: 3.Save balance.\n");
					printf("Main: 3.The act balance:%f.\n", temp_act.balance);
					printf("Main: 3.Save balance ok.\n");
					break;
				}
			
			case 4:	printf("---------------4.Withdraw Balance-------------------\n");
				printf("Input you id:");
				scanf("%ld", &temp_id);
				printf("Input you passsword:");
				scanf("%s", temp_password);
				printf("Input you balance:");
				scanf("%f", &temp_balance);
				ret_val = withdraw(&temp_act, temp_id, temp_password, temp_balance);
				if (3 == ret_val)
				{
					printf("Main: 4.password is error.\n");
					break;
				}
				else if (-1 == ret_val)
				{
					printf("Main: 4.The act is open or read error.\n");
					break;
				}
				else
				{
					printf("Main: 4.Withdraw balance success.\n");
					printf("Main: 4.The act balance is %f.\n", temp_act.balance);
					printf("Withdraw Ok.\n");
					break;
				}

			case 5:	printf("---------------5.Transfer Balance--------------------\n");
				printf("Input you id:");
				scanf("%ld", &temp_id);
				printf("Input you passsword:");
				scanf("%s", temp_password);
				printf("Input you balance:");
				scanf("%f", &temp_balance);
				printf("Input transer id:");
				scanf("%ld", &to_id);
				ret_val = transfer(&temp_act, temp_id, temp_password, temp_balance, to_id);
				if (3 == ret_val)
				{
					printf("Main: 5.password is error.\n");
					break;
				}
				else if (-1 == ret_val)
				{
					printf("Main: 5.The act is open or read error.\n");
					break;
				}
				else
				{
					printf("Main: 5.Transfer balance success.\n");
					printf("Main: 5.The transfer act balance is %f.\n", temp_act.balance);
					printf("Main: 5.Transfer Ok.\n");
					break;
				}

			case 6:	printf("---------------6.Exit System Menu-------------------\n");
				printf("Exit System Now.\n");
				return 0;
				break;
			case 7:	printf("---------------7.Enter You Choice-------------------\n");
			
				break;
			
			defalut:	printf("Please input you choice[1 - 7].\n");
				break;
	
		}

	}
	
	
	
	
	return 0;	
}










