#include <stdio.h>
#include <stdlib.h>
#include <time.h>


static void fill(int *p, int n) {
	time_t ts;
	unsigned int data = time(&ts);
	srand(data);
	for (int i = 0; i < n; i++)
		p[i] = rand() % 10;
}

static void print(int *p, int n) {
	for (int i = 0; i < n; i++)
		printf("%d\n", p[i]);
}

static int compare(const void *p1, const void *p2) {
	const int* px1 = p1;
	const int* px2 = p2;

	if (*px1 == *px2) {
		return 0;
	} else if (*px1 < *px2) {
		return -1;
	} else {
		return 1;
	}
}


int main(void) {
	int a[10];
	fill(a, 10);
	print(a, 10);

	qsort(a, sizeof(a) / sizeof(a[0]), sizeof(int), compare);
	 
	printf("qsort:\n");
	print(a, 10);
	return 0;
}
