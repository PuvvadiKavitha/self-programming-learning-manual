#include "my_array.h"


const int kMinInitCapacity = 1;
const int kMinCapacity = 16;
const int kGrowthFactor = 2;
const int kShrinkFactor = 4;

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



//void myarray_resize(MyArray *arrptr, int resize) {
//  
//}




int myarray_modify_capacity(int capacity) {
  if (capacity < kMinInitCapacity) {
    exit(-1);
  }
  else if (capacity <= kMinCapacity) {
    return kMinCapacity;
  }
  else {
    int really_capacity = kMinInitCapacity;
    // capacity <= really_capacity / 2，break while loop.
    //while (capacity > (really_capacity / kGrowthFactor))
    while (capacity > really_capacity)
      really_capacity *= kGrowthFactor;

    return really_capacity;
  }
}


void check_address(void *address) {
  if (NULL == address) {
    printf("Allocate memory failed.\n");
	exit(-1);
  }
}


void print_myarray(MyArray *arrptr) {
  printf("\nsize = %d\n", arrptr->size);
  printf("capacity = %d\n", arrptr->capacity);
  for (int i = 0; i < arrptr->size; i++)
    printf("data[i] = %d\n", arrptr->data[i]);

  putchar('\n');
}



int size(MyArray *arrptr) {
  assert((arrptr != NULL) && (arrptr->data != NULL));
  return arrptr->size;
}


int capacity(MyArray *arrptr) {
  assert((arrptr != NULL) && (arrptr->data != NULL));
  return arrptr->capacity;
}


int is_empty(MyArray *arrptr) {
  return !size(arrptr);
}


int at(MyArray *arrptr, int index) {
  assert((arrptr != NULL) && (arrptr->data != NULL));
  return arrptr->data[index];
}


void push(MyArray *arrptr, int item) {
  assert((arrptr != NULL) && (arrptr->data != NULL));
  arrptr->data[size(arrptr)] = item; 
  arrptr->size++;
}




