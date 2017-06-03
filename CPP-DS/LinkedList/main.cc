#include "linked_list.h"
#include "linked_list.cc"

#include <iostream>
#include <cassert>

#include "node.h"

void test_node(void) {
  Node<int> n1(1);
  Node<int> n2(2);
  Node<int> n3(3);
  
  std::cout << n1.data() << std::endl;
  std::cout << n2.data() << std::endl;
  std::cout << n3.data() << std::endl;

  n1.set_data(11);
  n2.set_data(22);
  n3.set_data(33);

  n1.set_next(&n2);
  n2.set_next(&n3);

  std::cout << n1.data() << std::endl;
  std::cout << (n1.next())->data() << std::endl;
  std::cout << (n2.next())->data() << std::endl;

}


void test_create_list(void) {
	LinkedList<int> link;
}


void test_push_front(void) {
  LinkedList<int> link;
  link.PushFront(1);
  link.PushFront(2);
  link.PushFront(3);
  link.PushFront(4);
  link.PushFront(5);
  
  link.PrintList();

}

void test_empty(void) {
  LinkedList<int> link;
  assert(link.Empty() == true);
  
  link.PushFront(1);
  link.PushFront(2);
  link.PushFront(3);
  link.PushFront(4);
  link.PushFront(5);
  
  assert(link.Empty() == false);
}

void test_size(void) {
  LinkedList<int> link;
  assert(link.Size() == 0);
  
  link.PushFront(1);
  link.PushFront(2);
  link.PushFront(3);
  link.PushFront(4);
  link.PushFront(5);
  
  assert(link.Size() == 5);
}



void test_value_at(void) {
  LinkedList<int> link;
  
  link.PushFront(1);
  link.PushFront(2);
  link.PushFront(3);
  link.PushFront(4);
  link.PushFront(5);
  
  link.PrintList();
  assert(link.ValueAt(0) == 5);
  assert(link.ValueAt(2) == 3);
  assert(link.ValueAt(4) == 1);
}


void test_pop_front(void) {
  LinkedList<int> link;
  
  link.PushFront(1);
  link.PushFront(2);
  link.PushFront(3);
  
  link.PrintList();
  
  assert(link.ValueAt(0) == 3);
  assert(link.Size() == 3);
  
  link.PopFront();
  link.PrintList();
  
  assert(link.ValueAt(0) == 2);
  assert(link.Size() == 2);
}

void test_push_back(void) {
  LinkedList<int> link;
  
  link.PushFront(1);
  link.PushFront(2);
  link.PushFront(3);
  
  link.PrintList();
  
  link.PushBack(2);
  link.PushBack(3);

  link.PrintList();
  
  assert(link.ValueAt(3) == 2);
  assert(link.Size() == 5);
}

void test_pop_back(void) {
  LinkedList<int> link;
  
  link.PushFront(1);
  link.PushFront(2);
  link.PushFront(3);
  
  link.PrintList();
  
  assert(link.PopBack() == 1);
  link.PrintList();
  assert(link.Size() == 2);
}


void test_front(void) {
  LinkedList<int> link;
  
  link.PushFront(1);
  link.PushFront(2);
  link.PushFront(3);
  
  assert(link.Front() == 3);
}



void test_back(void) {
  LinkedList<int> link;
  
  link.PushFront(1);
  link.PushFront(2);
  link.PushFront(3);
  
  assert(link.Back() == 1);
}


void test_insert(void) {
  LinkedList<int> link;
  
  link.PushFront(1);
  link.PushFront(2);
  link.PushFront(3);
 
  link.Insert(0, 0);
  link.Insert(1, 22);
  link.Insert(4, 22);
  
  link.PrintList();
}



void test_erase(void) {
  LinkedList<int> link;
  
  link.PushFront(1);
  link.PushFront(2);
  link.PushFront(3);
  link.PushFront(4);
  link.PushFront(5);
 
  link.PrintList();
  link.Erase(0);
  link.Erase(3);
  link.Erase(1);
}



void test_value_end(void) {
  LinkedList<int> link;
  
  link.PushFront(1);
  link.PushFront(2);
  link.PushFront(3);
  link.PushFront(4);

  assert(link.ValueNFromEnd(1) == 1);
  assert(link.ValueNFromEnd(3) == 3);
  assert(link.ValueNFromEnd(4) == 4);
}


void test_reverse(void) {
  LinkedList<int> link;
  
  link.PushFront(1);
  link.PushFront(2);
  link.PushFront(3);
  link.PushFront(4);

  link.PrintList();

  link.Reverse();

  link.PrintList();
}


void test_remove_value(void) {
  LinkedList<int> link;
  
  link.PushFront(1);
  link.PushFront(2);
  link.PushFront(2);
  link.PushFront(3);
  link.PushFront(4);


  link.PrintList();

  link.RemoveValue(2);
  
  link.PrintList();
}




void run_all_test(void) {
  //test_node();
  //test_create_list();
  //test_push_front();
  //test_empty();
  //test_size();
  //test_value_at();
  //test_pop_front();
  //test_push_back();
  //test_pop_back();
  //test_front();
  //test_back();
  //test_insert();
  //test_erase();
  //test_erase();
  //test_value_end();
  //test_reverse();
  test_remove_value();
}


int main(void) {
  run_all_test();
  return 0;
}




