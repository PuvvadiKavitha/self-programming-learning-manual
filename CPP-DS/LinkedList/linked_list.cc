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


template<typename T>
const T LinkedList<T>::PopFront() {
  T pop_value = head_->data();
  auto first = head_;
  head_ = head_->next();
  delete first;
  first = nullptr;
  return pop_value;
}


template<typename T>
void LinkedList<T>::PushBack(const T item) {
  auto new_node = new Node<T>(item);
  new_node->set_next(nullptr);

  auto current = head_;
  
  while (current->next())
	  current = current->next();
  
  current->set_next(new_node);
}



template<typename T>
const T LinkedList<T>::PopBack() {
  auto current = head_;
  Node<T> *prev = nullptr;

  while (current->next()) {
    prev = current;
	current = current->next();
  }

  T pop_value = current->data();
  prev->set_next(nullptr);
  
  delete current;
  current = nullptr;
  
  return pop_value;
}




