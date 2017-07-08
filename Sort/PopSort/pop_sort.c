#include <stdio.h>

static void pop_sort_four(int L[], int length) {
	int temp = 0;
	int isNeedSort = 1;

	for (int i = 0; (i < length) && isNeedSort; i++) {
		isNeedSort = 0;
		for (int j = length - 1; j > i; j--) {
			if (L[j - 1] > L[j]) { 
				temp = L[j - 1];
				L[j - 1] = L[j];
				L[j] = temp; 

				isNeedSort = 1;
			}
		}
	}
}




int main(void) {
	int x[10] = { 5, 3, 2, 1, 7, 4, 6, 9, 8, 10 };
	pop_sort_four(x, 10);
	for (int i = 0; i < 10; i++)
		printf("%d ", x[i]); 

	return 0;
}
