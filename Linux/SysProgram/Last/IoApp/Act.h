#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


//User Account
struct Act
{
    long id;
	char name[30];
	char password[20];
	char sex[10];
	int age;
	char tel[18];
	char address[300];
	float balance;
};

long GeneralId();
int getUserFileNameById(char*, int, long);
int createAct(struct Act*);
int queryAct(struct Act*, long, char*);
int showMenu();
int saveBalance(struct Act*, long, float);
int withdraw(struct Act*, long, char*, float);
int transfer(struct Act*, long, char*, float, long);












