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


int empty(node_t *head) {
  return head == NULL;
}


int value_at(node_t *head, int index) {
  if ((index + 1) > size(head))
	  return -1;
  
  node_t *current = head;
  
  for (int i = 0; i < index; i++)
	  current = current->next;
  
  return current->data;
}


void push_back(node_t **head, int item) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->data = item;
  new_node->next = NULL;

  if (*head == NULL) {
    *head = new_node;
	return;
  }

  node_t *current = *head;

  while (current->next)
	  current = current->next;
  
  current->next = new_node;
}


void print_list(node_t *head) {
  int list_size = size(head);
  node_t *current = head;
  for (int i = 0; i < list_size; i++) {
    printf("%d ", current->data);
	current = current->next;
  }
}




void push_front(node_t **head, int item) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->data = item;
  new_node->next = *head;
  *head = new_node;
}



int pop_front(node_t **head) {
  if (NULL == *head) {
    printf("Unable pop empty list.\n");
	return -1;
  }

  node_t *front_node = *head;
  *head = (*head)->next;
  int pop_value = front_node->data;
  free(front_node);
  return pop_value;
}


int pop_back(node_t **head) {
  if (NULL == *head) {
    printf("Unable pop empty list.\n");
	return -1;
  }

  node_t *current = *head;
  node_t *prev = NULL;

  while (current->next) {
    prev = current;
    current = current->next;
  }
  
  int pop_value = current->data;
  
  if (prev) 
    prev->next = NULL;
  else
    *head = NULL;

  free(current);
  current = NULL;

  return pop_value;
}



int front(node_t *head) {
  return head->data;
}



int back(node_t *head) {
 node_t *current = head;
 
 while (current->next)
   current = current->next;
 
 return current->data;
}


