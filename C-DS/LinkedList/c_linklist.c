#include "c_linklist.h"

int size(node_t *head) {
  int size = 0;
  node_t *current = head;
  
  while (current) {
    size++;
	current = current->next;
  }

  return size;
}





