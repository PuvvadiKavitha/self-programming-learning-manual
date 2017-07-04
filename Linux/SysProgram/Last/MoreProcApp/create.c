#include "bank_msg.h"

int create(struct C_Msg* reqmsg, struct Response_Msg* resmsg)
{
	char fname[50];
	memset(fname, 0, 50);
	long id = reqmsg->cm.id;
	int d = getNameById(fname, 50, id);
	if (d != 0)
	{
		printf("Create:get file name error\n");
		return -1;
	}
	int fd = open(fname, O_CREAT | O_WRONLY, 0666);
	if (fd < 0)
	{
		printf("Create:create act file error\n");
		return -1;
	}
	struct AccountW p;
	p.id = reqmsg->cm.id;
	strcpy(p.name, reqmsg->cm.name);
	strcpy(p.passwd, reqmsg->cm.passwd);
	p.balance = reqmsg->cm.balance;
	write(fd, &p, sizeof(p));
	resmsg->resm.id = p.id;
	resmsg->resm.balance = p.balance;
	resmsg->type = reqmsg->cm.pid;
	return 0;
}

int main()
{
	makeDaemon();
	int reqqid = msgget(ReqKEY1, 0);
	if (reqqid < 0)
	{
		printf("Create Main:Get reqqid error\n");
		return -1;
	}
	int resqid = msgget(ResKEY2, 0);
	if (resqid < 0)
	{
		printf("Create Main:Get resqid error\n");
		return -1;
	}
	struct C_Msg cmsg;
	struct Response_Msg resmsg;
	int fh;
	while (1)
	{
		int r = msgrcv(reqqid, &cmsg, sizeof(cmsg), 1, 0);
		if (r < 0)
		{
			printf("Create Main:Receiver not create msg");
			return -1;
		}
		fh = create(&cmsg, &resmsg);
		if (fh != 0)
		{
			printf("Create Main:Create act fail\n");
			return -1;
		}
		else
		{
			int r1 = msgsnd(resqid, &resmsg, sizeof(resmsg), 0);
			if (r1 < 0)
			{
				printf("Create Main:Not send resmsg\n");
				return -1;
			}
			else
			{
				printf("Create Main:Send resmsg ok\n");
			}
		}

	}

	return 0;
}
















