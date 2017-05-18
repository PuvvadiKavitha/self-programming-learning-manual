/**
 * @file Ex_1_1_21.c
 * @synopsis  Ex_1_1_21.c
 * @author cheng-zhi, chengzhihjy@gmail.com
 * @version 1.0
 * @date 2017-05-18
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>





/**
 * @synopsis  main 
 *
 * @return   
 */
int main1(void)
{
	char name[10] = { 0 };
	int a = 0;
	int b = 0;

	
	char *array[100] = { NULL };
	int i = 0;
	
	while (scanf("%s %d %d", name, &a, &b))
	{

		if (!strcmp(name, "quit"))
			break;
		array[i] = (char *)malloc(sizeof(char) * 50);
		memset(array[i], 0, sizeof(char) * 50);
		
		sprintf(array[i], "%s\t%d\t%d\t%0.3f\n", name, a, b, ((double)a) / b);
		
		i++;
	}

	puts("name\ta\tb\ta/b\n");
	for (int j = 0; j < i; j++)
	{
		printf("%s", array[j]);
	}


	return 0;
}


