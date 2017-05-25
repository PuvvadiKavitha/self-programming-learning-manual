#include "my_array.h"

#include <stdio.h>
#include <stdlib.h>





/**
 * @synopsis  main 
 *
 * @return   
 */
int main(int argc, char** argv)
{
	MyArray* array = myarray_new(atoi(argv[1]));
	
	push(array, 1);
	push(array, 2);
	push(array, 3);
	push(array, 4);
	push(array, 5);
	push(array, 6);
	
	print_myarray(array);
	myarray_delete(array);

	return 0;
}









