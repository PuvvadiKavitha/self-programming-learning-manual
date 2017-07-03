#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void fill(int* p, int n)
{
	time_t ts;
	unsigned int data = time(&ts);
	srand(data);
	for (int i = 0; i < n; i++)
	{
		p[i] = rand() % 1000;
		printf("%d   ", p[i]);
	}
}

void print(int* p, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d   ", p[i]);
	}
}

static int compare(void* p1, void* p2)
{
	int* px1 = p1;
	int* px2 = p2;
	if (*px1 == *px2)
	{
		return 0;
	}
	else if (*px1 < *px2)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}


int main15(void)
{
	int a[1000];
	fill(a, 1000);
	print(a, 1000);

	qsort(a, sizeof(a) / sizeof(a[0]), sizeof(int), compare);
	 
	printf("ÅÅÐòÒÔºó\n");
	print(a, 1000);
	system("pause");
	return 0;
}