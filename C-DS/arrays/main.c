#include "my_array.h"

#include <stdio.h>
#include <stdlib.h>



void test_resize() {
  CArray *array = carray_new(2);

  int old_capacity = carray_capacity(array);
  assert(old_capacity == 16);

  for (int i = 0; i < 18; i++) {
    carray_push(array, i + 1);
  }
  //printf("capacity = %d", carray_capacity(array));
  assert(carray_capacity(array) == 32);

  for (int j = 0; j < 15; j++) {
    printf("%d ", carray_pop(array));
  }

  putchar('\n');

  assert(carray_capacity(array) == 16);

  carray_destroy(array);
}


void run_all_test() {
  test_resize();
}

int main() {
  run_all_test();
}

/**
 * @synopsis  main 
 *
 * @return   
 */
int main1(int argc, char** argv)
{
	CArray* array = carray_new(atoi(argv[1]));
	
	carray_push(array, 1);
	carray_push(array, 2);
	carray_push(array, 3);
	carray_push(array, 4);
	carray_push(array, 5);
	carray_push(array, 6);
	print_carray(array);

	carray_insert(array, 2, 22);
	print_carray(array);
	
    carray_prepend(array, 11);	
	print_carray(array);
	
	carray_pop(array);
	print_carray(array);

	carray_delete(array, 4);
	print_carray(array);

	printf("find 2 index = %d\n", carray_find(array, 2));


	carray_destroy(array);

	return 0;
}

