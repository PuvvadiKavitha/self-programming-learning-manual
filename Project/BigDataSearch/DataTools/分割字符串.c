#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct Data
{
	int num;
	char str[40];

};
int main654(void)
{
	char str[1024] = "498626360----as15902036628";
	if (NULL == strstr(str, "----"))//�����Ӵ�
	{
		printf("����������\n");
		return -1;
	}
	char str1[50] = { 0 };
	char str2[50] = { 0 };

	char* p = strchr(str, '-');//����ָ�����ַ�
	*p = '\0';
	
	//strcpy(str1, str);//����
	//strcpy(str2, p + 4);

	struct Data data;
	data.num = atoi(str);//�ַ���ת��Ϊ����
	strcpy(data.str, p + 4);
	printf("%d   %s\n", data.num, data.str);
	 
	system("pause");
	return 0;
}