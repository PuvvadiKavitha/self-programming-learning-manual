#include <stdio.h>


/*
 * Ex_1_1_12.c
 */
static void show(void)
{
	int a[10] = { 0 };
	
	// 9 8 7 6 5 4 3 2 1 0
	for (int i = 0; i < 10; i++)
	{
		a[i] = 9 - i;
		printf("%d ", a[i]);
	}
	
	putchar('\n');
	
	//0 1 2 3 4 3 2 1 0
	for (int i = 0; i < 10; i++)
	{
		//Note that: a[5] != 5, because a[5] = a[4], a[4] = 4, so a[5] = 4
		a[i] = a[a[i]];
		printf("%d ", a[i]);
	}

	putchar('\n');
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);


}

int main(int argc, char **argv)
{
	show();
	putchar('\n');
	return 0;
}

