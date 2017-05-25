#ifndef MY_ARRAY_H_
#define MY_ARRAY_H_


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct MyArray {
  int *data;
  int size;
  int capacity;
} MyArray;


// Create a new array with capacity.
MyArray *myarray_new(int capacity);

// Delete arrptr memory.
void myarray_delete(MyArray *arrptr);

// Modify user input capacity to power of 2 - 16, 32, 64, 128
int myarray_modify_capacity(int capacity);

// Check address wheather is NULL or no.
void check_address(void *address);

// Output arrptr something.
void print_myarray(MyArray *arrptr);

// Return myarray size.
int size(MyArray *arrptr);

// Return myarray capacity.
int capacity(MyArray *arrptr);

// Return true if myarray is empty.
int is_empty(MyArray *arrptr);

// Return arrptr->data[index] value.
int at(MyArray *arrptr, int index);

// Input item to arrptr->data
void push(MyArray *arrptr, int item);






#endif //MY_ARRAY_H_



