#ifndef MY_ARRAY_H_
#define MY_ARRAY_H_


#include <assert.h>



typedef struct MyArray {
  int *data;
  int size;
  int capacity;
} MyArray;


/* Create a new array with capacity. */
MyArray *myarray_new(int capacity);










