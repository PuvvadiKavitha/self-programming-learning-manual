#ifndef _MAX_HEAP_H
#define _MAX_HEAP_H


#include <stdio.h>


const int kQueueCapacity = 1000;

typedef struct {
	int size;
	int elements[kQueueCapacity + 1];
	int capacity;
} MaxHeap;

void maxheap_insert(MaxHeap *heap, int value);

void maxheap_sift_up(MaxHeap *heap, int heap_size);

int maxheap_get_max(MaxHeap *heap);

int maxheap_get_size(MaxHeap *heap);

int maxheap_is_empty(MaxHeap *heap);

int maxheap_extract_max(MaxHeap *heap);

int maxheap_sift_down(MaxHeap *heap, int index);

void maxheap_remove_node(MaxHeap *heap, int index);

void maxheap_heapify(int *numbers, int count);

void maxheap_percolate_down(int *numbers, int count, int index);

#endif //_MAX_HEAP_H
