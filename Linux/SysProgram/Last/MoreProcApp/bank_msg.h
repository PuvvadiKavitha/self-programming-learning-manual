#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

#ifndef __BANKMSG__
#define __BANKMSG__
struct AccountW
{
	long id;
	char name[20];
	char passwd[30];
	float balance;
};

struct C_Message 
{
	long id;
	char name[20];
	char passwd[30];
	float balance;
	int pid;
};
struct C_Msg
{
	long type;
    struct	C_Message cm;

};


struct S_Message
{
	long id;
	float balance;
	int pid;
};
struct S_Msg
{
	long type;
	struct S_Message sm;
};

struct W_Message
{
	long id;
	char passwd[30];
	float balance;
	int pid;
};
struct W_Msg
{
	long type;
	struct W_Message wm;
};


struct Q_Message
{
	long id;
	char passwd[30];
	int pid;
};
struct Q_Msg
{
	long type;
	struct Q_Message qm;
};

struct T_Message
{
	long fromid;
	char frompasswd[30];
	float balance;
	long toid;
	int pid;
};
struct T_Msg
{
	long type;
	struct T_Message tm;
};

struct Response_Message
{
	long id;
	float balance;
};
struct Response_Msg
{
	long type;
	struct Response_Message resm;
};

const int ReqKEY1 = 0x1234;
const int ResKEY2 = 0x3456;

void makeDaemon();
long GeneralId();
int getNameById(char*, int, long);
int showMenu();

#endif
