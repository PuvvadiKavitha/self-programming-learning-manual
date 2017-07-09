#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


struct info
{
	int id;//   4
	char str[50];//50       
	              //字节对齐56  要能整除最宽基本数据类型double  8
};

int compare_by_id(void* p1, void* p2)
{
	//struct info* px1 = p1;
	//struct info* px2 = p2;
	return (((struct info*)p1)->id - ((struct info*)p2)->id);
// 	if (px1->id == px2->id)
// 	{
// 		return 0;
// 	}
// 	else if (px1->id < px2->id)
// 	{
// 		return -1;//-1代表小于
// 	}
// 	else if (px1->id > px2->id)
// 	{
// 		return 1;//代表大于
// 	}
}
 

int compare_by_name(void* p1, void* p2)
{
	//struct info* px1 = p1;
	//struct info* px2 = p2; 
	return strcmp(((struct info*)p1)->str, ((struct info*)p2)->str);



}

int main3345(void)
{
	struct info in[] = {
		{11, "chengzhi01"},
		{22, "sadfsdfwe"},
		{3, "vertsfasf"},
		{4, "asffsdfsdf"}
	};
	printf("%d %d\n\n", sizeof(struct info), sizeof(in[0]));

	qsort(in, sizeof(in) / sizeof(struct info), sizeof(struct info), compare_by_id);
	for (int i = 0; i < 4; i++)
	{
		printf("%d %s\n", in[i].id, in[i].str);
	}
	printf("\n\n\n");

	qsort(in, sizeof(in) / sizeof(in[0]), sizeof(in[0]), compare_by_name);
	for (int i = 0; i < 4; i++)
	{
		printf("%d %s\n", in[i].id, in[i].str);
	}
	system("pause");
	return 0;
}
