#include <stdio.h>
#define N 5

void main() {
	
	int b[] = { 1, 2, 3 };
	int a[N] = { 1, 2, 3, 4, 5 };
	int *p = a;
	
	// Array is const var, don`t be modify.
	//a = 2;
	printf("a = %p\n", a);
	for (int i = 0; i < (sizeof(a) / sizeof(a[0])); i++)
		printf("%d ", a[i]);
	

	printf("\n");
	char   *p1 = NULL;
	float  *p2 = NULL;
	double *p3 = NULL;
	// 32: 4, 4, 4  64: 8, 8, 8
	printf("sizeof(char *) = %d\nsizeof(float *) = %d\nsizeof(double *) = %d\n", sizeof(p1), sizeof(p2), sizeof(p3));
	// 1 4 8
	printf("sizeof(char) = %d\nsizeof(float) = %d\nsizeof(double) = %d\n", sizeof(*p1), sizeof(*p2), sizeof(*p3));
}