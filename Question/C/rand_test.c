#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {  
	// Will only produce a constant random number, such as zeor.
	//srand(10);

    /* 
     * Seed the random-number generator with current time so that 
     * the numbers will be different every time we run. 
     */
	srand((unsigned int)time(NULL));

	// Generates a random number of [0, 5 - 1]
	int num = rand() % 5;
	printf("num = %d\n", num);
	  
	return 0;
}
