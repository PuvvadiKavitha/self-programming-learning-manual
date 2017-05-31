#include "c_linklist.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void test_size() {
  node_t *head = (node_t *)malloc(sizeof(node_t));
  
  head->data = 1;
  head->next = NULL;

  assert(size(head) == 1);

}


int main(void) {

}
