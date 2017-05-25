#include "my_array.h"


const int g_min_init_capacity = 1;
const int g_min_capacity = 16;
const int g_growth_factor = 2;
const int g_shrink_factor = 4;

MyArray *myarray_new(int capacity) {
  int really_capacity = myarray_modify_capacity(capacity);
  MyArray *array = (MyArray *)malloc(sizeof(MyArray));
  check_address(array);

  array->data = (int *)malloc(sizeof(int) * really_capacity);
  check_address(array->data);
  array->capacity = really_capacity;
  array->size = 0;
}


void myarray_delete(MyArray *arrptr) {
  free(arrptr->data);
  arrptr->data = NULL;
  free(arrptr);
  arrptr = NULL;
}

void myarray_resize(MyArray *arrptr, int resize) {
  
}











int myarray_modify_capacity(int capacity) {
  if (capacity < g_min_init_capacity)
    exit(EXIT_FAILURE);

  int really_capacity = g_min_init_capacity;

  while (capacity > (really_capacity / g_growth_factor))
    really_capacity *= g_growth_factor;
  return really_capacity;
}




void check_address(void *address) {
  if (NULL == address) {
    printf("Allocate memory failed.\n");
	exit(EXIT_FAILURE);
  }

}


























/**
* @synopsis  main 
*
* @param argc
* @param argv
*
* @returns   
*/
int main(int argc, char **argv)
{

	return 0;
}


