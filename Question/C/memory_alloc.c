#include <stdio.h>
#include <stdlib.h>

int main() {
	// No auto init zeor.
	int* pm = (int*)malloc(sizeof(int)* 5);

	// Auto init zeor.
	int* pc = (int*)calloc(5, sizeof(int));

	// Add memory.
	int addnum = 5; 
	int* pr = (int*)realloc((void*)pm, sizeof(int) * (5 + addnum));

	//free(pm);	don`t free, it is include in pr.
	free(pc);
	free(pr);
	return 0;
}