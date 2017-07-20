#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct info {
	int id;
	char str[50];    
	//字节对齐56  要能整除最宽基本数据类型 double 8
};



int compare_by_id(const void *p1, const void *p2) {
	return (((struct info*)p1)->id - ((struct info*)p2)->id);
}
 

int compare_by_name(const void *p1, const void *p2) {
	return strcmp(((struct info*)p1)->str, ((struct info*)p2)->str);
}

int main(void) {
	struct info in[] = {
		{11, "chengzhi01"},
		{22, "sadfsdfwe" },
		{3 , "vertsfasf" },
		{4 , "asffsdfsdf"}
	};

	// 56, 56
	printf("sizeof(struct info) = %d, sizeof(in[0]) = %d\n\n", sizeof(struct info), sizeof(in[0]));

	qsort(in, sizeof(in) / sizeof(struct info), sizeof(struct info), compare_by_id);
	
	for (int i = 0; i < 4; i++)
		printf("%d %s\n", in[i].id, in[i].str);
	
	printf("\n\n\n");

	qsort(in, sizeof(in) / sizeof(in[0]), sizeof(in[0]), compare_by_name);
	
	for (int i = 0; i < 4; i++)
		printf("%d %s\n", in[i].id, in[i].str);
	
	return 0;
}
