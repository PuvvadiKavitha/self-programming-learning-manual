#include "linked_list.h"

#include <iostream>

template<typename T>
LinkedList<T>::LinkedList() : head_(nullptr) {

}


template<typename T>
LinkedList<T>::~LinkedList() {
  Node<T> *current = head_;
  Node<T> *next = nullptr;

  while (current) {
    next = current->next();
	delete current;
	current = next;
  }
}



template<typename T>
const int LinkedList<T>::Size() {
  int size = 0;

  auto current = head_;

  while (current) {
    size++;
	current = current->next();
  }

  return size;

}



template<typename T>
bool LinkedList<T>::Empty() {
  return head_ == nullptr;
}


template<typename T>
const T& LinkedList<T>::ValueAt(int index) {
  auto current = head_;

  for (int i = 0; (i < index) && current; i++)
	  current = current->next();

  if (current == nullptr) {
    std::cout << "Index is out of bounds." << std::endl;
	exit(EXIT_FAILURE);
  }

  return current->data();
}



template<typename T>
void LinkedList<T>::PushFront(const T item) {
  auto new_node = new Node<T>(item);
  new_node->set_next(head_);
  head_ = new_node;
}



template<typename T>
void LinkedList<T>::PrintList() {
  std::cout << std::endl;
  
  for (auto current = head_; current; current = current->next()) {
    std::cout << current->data() << " -> ";
  }
  
  std::cout << std::endl;
}



