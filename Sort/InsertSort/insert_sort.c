#include <stdio.h> 

static void insert_sort(int L[], int length) {  
	int temp = 0;
	int j = 0;

	for (int i = 1; i < length; i++) {
		if (L[i - 1] > L[i]) {
			temp = L[i];
			for (j = i; (j > 0) && (L[j - 1] > temp); j--)
				L[j] = L[j - 1];
			
			L[j] = temp;
		}
	} 
}


int main(void) {
	int x[10] = { 5, 3, 2, 1, 7, 4, 6, 9, 8, 10 };
	
	insert_sort(x, 10);

	for (int i = 0; i < 10; i++)
		printf("%d ", x[i]);

	printf("\n");
	return 0;
}