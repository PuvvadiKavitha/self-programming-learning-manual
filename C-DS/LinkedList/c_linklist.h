#ifndef C_LINKLIST_H_
#define C_LINKLIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
}node_t;

// Return the link list node size.
int size(node_t *head);

// Return true if head == NULL.
int empty(node_t *head);

// Return value at index.
int value_at(node_t *head, int index);

// Add a new node to the link.
void push_back(node_t **head, int item);

// Print list.
void print_list(node_t *head);

// Add a new node to the link header.
void push_front(node_t **head, int item);

// Return first node->data and remove it.
int pop_front(node_t **head);

// Return last node->data and remove it.
int pop_back(node_t **head);

// Return front value.
int front(node_t *head);

// Return last value.
int back(node_t *head);

#endif //C_LINKLIST_H_





