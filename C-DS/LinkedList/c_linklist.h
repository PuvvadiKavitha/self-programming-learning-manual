#ifndef C_LINKLIST_H_
#define C_LINKLIST_H_

#include <stdio.h>

typedef struct Node {
  int data;
  struct Node *next;
}node_t;

// Return the link list node size.
int size(node_t *head);


#endif //C_LINKLIST_H_
