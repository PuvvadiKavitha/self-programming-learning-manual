#include <stdio.h>
#include <stdlib.h>
#include <time.h>


static void select_sort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min_i = i;
		
		for (int j = i + 1; j < 10; j++) {
			if (a[j] < a[min_i])
				min_i = j;
		}

		if (min_i != i) {
			a[min_i] = a[min_i] ^ a[i];
			a[i] = a[i] ^ a[min_i];
			a[min_i] = a[min_i] ^ a[i];
		}
	}
}



void main()
{
	time_t ts;
	srand((unsigned int)time(&ts));
	int a[10] = { 0 }; 
	for (int i = 0; i < 10;i++) {
		a[i] = rand() % 100;
		printf("%d\t%x\n", a[i], &a[i]);
	} 

	
	printf("\n\n");
	select_sort(a, sizeof(a));

	printf("select_sort:\n\n");
	for (int i = 0; i < 10; i++)
		printf("%d\t%x\n", a[i], &a[i]);
	
	 
}